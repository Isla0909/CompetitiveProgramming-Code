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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

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
using Z = MInt<M1>;

Z fac[N], invfac[N];
void initial()
{
	fac[0] = invfac[0] = 1;
	for(int i = 1; i < N; i ++)
	{
		fac[i] = fac[i - 1] * i;
		invfac[i] = invfac[i - 1] * power(Z(i), mod - 2);
	}
}

Z binom(int n, int m)
{
	if(n < m || m < 0) return 0;
	return fac[n] * invfac[m] * invfac[n - m];
}
//注:函数开始时必须调用initial

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	initial();

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		string s; cin >>s;

		if(count(s.begin(), s.end(), '1') < k)
		{
			cout <<0 <<endl;
			continue;
		}

		s = ' ' + s; int cnt = 0;
		vector<int> pos(n + 1, 1), pre(n + 1);
		for(int i = 1, j = 1; i <= n; i ++)
		{
			pre[i] = pre[i - 1] + (s[i] == '1');
			if(s[i] == '1') cnt ++;

			while(cnt > k)
			{
				if(s[j ++] == '1') cnt --;
			}
			if(cnt < k) pos[i] = 1;
			else pos[i] = j;
		}
		vector<Z> f(n + 1); f[0] = 1;
		for(int i = 1; i <= n; i ++)
		{
			f[i] = f[i - 1];
			
			if(s[i] == '1')//1换0
			{
				if(i - pos[i] + 1 == pre[i] - pre[pos[i] - 1]) continue;

				f[i] += binom(i - pos[i], pre[i] - pre[pos[i] - 1]);
			}
			else
			{
				if(pre[i] - pre[pos[i] - 1])
					f[i] += binom(i - pos[i], pre[i] - pre[pos[i] - 1] - 1);
			}
		}
		cout <<f[n] <<endl;	
	}
	return 0;
}