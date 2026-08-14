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
//注:使用前记得修改模数!!

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		vector<vector<int>> adj(n + 1);
		for(int i = 2; i <= n; i ++)
		{
			int u = i, v; cin >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<Z> down(n + 1);
		auto dfs1 = [&](this auto &&self, int u, int fa) -> void
		{
			Z res = 1;
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
				res = res * (1 + down[v]);
			}
			down[u] = res;
		};
		dfs1(1, -1);

		vector<Z> up(n + 1);
		auto dfs2 = [&](this auto &&self, int u, int fa) -> void
		{
			vector<int> son;
			for(auto v : adj[u])
			{
				if(v == fa) continue;
				son.push_back(v);
			}

			int m = son.size();
			vector<Z> pre(m + 1), suf(m + 1);
			pre[0] = 1;
			for(int i = 0; i < m; i ++)
			{
				int v = son[i];
				pre[i + 1] = pre[i] * (1 + down[v]);
			}

			suf[m] = 1;
			for(int i = m - 1; i >= 0; i --)
			{
				int v = son[i];
				suf[i] = suf[i + 1] * (1 + down[v]);
			}

			for(int i = 0; i < m; i ++)
			{
				int v = son[i];
				Z res = pre[i] * suf[i + 1];
				up[v] = res * (1 + up[u]);
				self(v, u);
			}
		};
		dfs2(1, -1);	

		vector<Z> p(n + 1), e(n + 1);
		for(int u = 1; u <= n; u ++)
		{
			p[u] = down[u] * (1 + up[u]);
			e[u] = down[u] * up[u];
		}

		vector<int> dep(n + 1);
		int len = __lg(n) + 1;
		vector f(n + 1, vector<int>(len + 1));
		vector<Z> prep(n + 1), pree(n + 1);
		auto dfs3 = [&](this auto &&self, int u, int fa) -> void
		{
			dep[u] = dep[fa] + 1;
			f[u][0] = fa;

			for(int j = 1; j < len; j ++)
				f[u][j] = f[f[u][j - 1]][j - 1];

			for(auto v : adj[u])
			{
				if(v == fa) continue;
				prep[v] = prep[u] + p[v];
				pree[v] = pree[u] + e[v];
				self(v, u);
			}
		};

		prep[1] = p[1], pree[1] = e[1];
		dfs3(1, 0);

		auto lca = [&](int a, int b) -> int
		{
			if(dep[a] < dep[b]) swap(a, b);

			for(int k = len - 1; k >= 0; k --)
				if(dep[f[a][k]] >= dep[b])
					a = f[a][k];

			if(a == b) return b;

			for(int k = len - 1; k >= 0; k --)
				if(f[a][k] != f[b][k])
				{
					a = f[a][k];
					b = f[b][k];
				}
			return f[a][0];
		};

		while(q --)
		{
			int u, v; cin >>u >>v;
			int P = lca(u, v);
			Z p_val = prep[u] + prep[v] - 2 * prep[P] + p[P];
			Z e_val = pree[u] + pree[v] - 2 * pree[P];
			cout <<p_val - e_val <<endl;
		}
	}
	return 0;
}
