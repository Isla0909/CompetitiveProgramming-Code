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

struct Info
{
	int siz = 0;
	array<int, 10> a{};
};

Info merge(const Info &x, const Info &y)
{
	Info res;
	int i = 0, j = 0;
	while(res.siz < 10 && (i < x.siz || j < y.siz))
	{
		if(j == y.siz || i < x.siz && x.a[i] < y.a[j])
			res.a[res.siz ++] = x.a[i ++];
		else
			res.a[res.siz ++] = y.a[j ++];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<Info> city(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		int x; cin >>x;
		if(city[x].siz < 10) city[x].a[city[x].siz ++] = i;
	}

	vector<int> dep(n + 1);
	int len = __lg(n) + 1;
	vector f(n + 1, vector<int>(len));
	vector val(n + 1, vector<Info>(len));
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa, val[u][0] = city[u];

		for(int j = 1; j < len; j ++)
		{
			f[u][j] = f[f[u][j - 1]][j - 1];
			val[u][j] = merge(val[u][j - 1], val[f[u][j - 1]][j - 1]);
		}

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
		}
	};
	dfs(1, 0);

	auto lca = [&](int a, int b)
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int j = len - 1; j >= 0; j --)
			if(dep[f[a][j]] >= dep[b])
				a = f[a][j];

		if(a == b) return b;

		for(int j = len - 1; j >= 0; j --)
			if(f[a][j] != f[b][j])
			{
				a = f[a][j];
				b = f[b][j];
			}
		return f[a][0];
	};

	auto climb = [&](int u, int k, Info &res) -> void
	{
		for(int j = len - 1; j >= 0; j --)
			if(k >> j & 1)
			{
				res = merge(res, val[u][j]);
				u = f[u][j];
			}
	};

	while(q --)
	{
		int u, v, a; cin >>u >>v >>a;
		int p = lca(u, v);

		Info res;
		climb(u, dep[u] - dep[p], res);
		climb(v, dep[v] - dep[p], res);

		res = merge(res, city[p]);
		int cnt = min(a, res.siz);
		cout <<cnt <<" \n"[cnt == 0];
		for(int i = 0; i < cnt; i ++)
			cout <<res.a[i] <<" \n"[i == cnt - 1];
	}
	return 0;
}
