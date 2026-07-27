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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

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
using Z = MInt<M1>;

struct Comb
{
	int n;
	vector<Z> _fac, _invfac, _inv;

	void initial(int m)
	{
		if(m <= n) return ;
		_fac.resize(m + 1);//阶乘
		_invfac.resize(m + 1);//阶乘逆元
		_inv.resize(m + 1);//逆元

		for(int i = n + 1; i <= m; i ++)
			_fac[i] = _fac[i - 1] * i;
		_invfac[m] = _fac[m].inv();//倒推少个log
		for(int i = m; i > n; i --)
		{
			_invfac[i - 1] = _invfac[i] * i;
			_inv[i] = _fac[i - 1] * _invfac[i];
		}
		n = m;
	}

	Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {};
	Comb(int n) : Comb()
	{
		initial(n);
	}

	Z fac(int x)
	{
		if(x > n) initial(2 * x);
		return _fac[x];
	}
	Z invfac(int x)
	{
		if(x > n) initial(2 * x);
		return _invfac[x];
	}
	Z inv(int x)
	{
		if(x > n) initial(2 * x);
		return _inv[x];
	}
	Z C(int x, int y)
	{
		if(x < 0 || y < 0 || x < y) return 0;
		return fac(x) * invfac(y) * invfac(x - y);
	}
	Z P(int x, int y)
	{
		if(x < 0 || y <  0 || x < y) return 0;
		return fac(x) * invfac(x - y);
	}
}comb(1 << 21);
//注:使用前记得修改模数!!

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	string s; cin >>s;
	s = " " + s;
	if(count(s.begin(), s.end(), '1') < k)
	{
		cout <<1 <<endl;
		return 0;
	}

	vector<int> pos(n + 1, 1), pre(n + 1);
	int cnt = 0;
	for(int i = 1, j = 1; i <= n; i ++)
	{
		pre[i] = pre[i - 1] + (s[i] == '1');
		if(s[i] == '1') cnt ++;

		while(cnt > k)
		{
			if(s[j] == '1') cnt --;
			j ++;
		}
		pos[i] = j;
	}

	vector<Z> f(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == '1')
		{
			if(pre[i] - pre[pos[i] - 1] == i - pos[i] + 1) continue;
			else f[i] += comb.C(i - pos[i] + 1 - 1, pre[i] - pre[pos[i] - 1]);
		}
		else
		{
			if(i - pre[pos[i] - 1])
				f[i] += comb.C(i - pos[i] + 1 - 1, pre[i] - pre[pos[i] - 1] - 1);
		}
	}
	Z ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += f[i];
	cout <<ans + 1 <<endl;
	return 0;
}
