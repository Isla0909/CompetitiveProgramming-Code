#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#include <ctime>
#include <random>
#include <chrono>
#include <functional>
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

template <class T>
constexpr T power(T a, i64 b)
{
    assert(b >= 0);
    T res = 1;
    while(b)
    {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p)
{
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;

    if(res < 0) res += p;
    return res;
}

template <i64 P>
struct MLong
{
    i64 x; //x ≡ value (mod Mod)
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x_) : x{norm(x_ % getMod())} {}

    static i64 Mod;
    constexpr static i64 getMod()
    {
        //P > 0为静态档, P <= 0为动态档, 模数是Mod
        return P > 0 ? P : Mod;
    }
    //动态修改Mod -> Z::setMod(p)
    constexpr static void setMod(i64 Mod_)
    {
        Mod = Mod_;
    }
    //归一化处理
    constexpr i64 norm(i64 x) const//const保证限制成员变量不被修改 
    {
        if(x < 0) x += getMod();
        if(x >= getMod()) x -= getMod();
        return x;
    }
    constexpr i64 val() const
    {
        return x;
    }
    explicit constexpr operator i64() const
    {
        return x;
    }
    constexpr MLong operator-() const
    {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) &//right-hand side右操作数
    {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) &
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) &
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) &
    {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs)//虽然不是私有成员,加上friend便于以后的维护
    {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr istream &operator>>(istream &is, MLong &a)
    {
        i64 v;
        is >>v;
        a = MLong(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MLong &a)
    {
        return os<< a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs)
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs)
    {
        return lhs.val() != rhs.val();
    }
};

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x_) : x{norm(x_ % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        return P > 0 ? P : Mod;
    }
    constexpr static void setMod(int Mod_) 
    {
        Mod = Mod_;
    }
    constexpr int norm(int x) const 
    {
        if (x < 0) x += getMod();
        if (x >= getMod()) x -= getMod();
        return x;
    }
    constexpr int val() const 
    {
        return x;
    }
    explicit constexpr operator int() const 
    {
        return x;
    }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr istream &operator>>(istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) 
    {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) 
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) 
    {
        return lhs.val() != rhs.val();
    }
};

constexpr int M1 = 998244353, M2 = 1e9 + 7;
constexpr i64 M3 = i64(1e18) + 9;
using Z = MInt<M2>;

int remove_bit(int mask, int x)
{
	return (mask & ((1 << x) - 1)) | ((mask >> (x + 1)) << x);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		int k; cin >>k;
		vector<int> g(n);
		for(int i = 0; i < k; i ++)
		{
			int x; cin >>x;
			x --;
			g[x] = 1;
		}

		if(m == 1)
		{
			cout <<1 <<endl;
			continue;
		}

		//f[i][j] 表示当前剩余i堆,状态为j时的
		vector<vector<int>> f(n + 1);
		for(int i = 1; i <= n; i ++)
			f[i].assign(1 << i, (n - i) % 2);

		f[1][0] = 0, f[1][1] = 1;
		for(int i = 2; i <= n; i ++)
		{
			if((n - i) % 2 == 0)//Alice
			{
				for(int j = 0; j < (1 << i); j ++)
				{
					for(int k = 0; k < i; k ++)
					{
						if(!g[k]) continue;
						f[i][j] = f[i][j] | f[i - 1][remove_bit(j, k)];
					}
				}
			}
			else//Bob
			{
				for(int j = 0; j < (1 << i); j ++)
				{
					for(int k = 0; k < i; k ++)
					{
						if(!g[k]) continue;
						f[i][j] = f[i][j] & f[i - 1][remove_bit(j, k)];
					}
				}
			}
		}


		vector<int> w(n + 1);
		for(int i = 0; i < (1 << n); i ++)
			w[__builtin_popcount(i)] += f[n][i];

		Z ans = 0;
		for(int i = 1; i <= m; i ++) 
    		for (int j = 0; j <= n; j ++)
        		ans += w[j] * power(Z(m - i + 1), j) * power(Z(i - 1), n - j);
        cout <<ans <<endl;
	}
	return 0;
}