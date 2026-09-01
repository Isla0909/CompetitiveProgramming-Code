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

struct DSU
{
	int n;
	vector<int> p, sum;

	DSU(int n = 0)
	{
		initial(n);
	}

	void initial(int n)
	{
		this -> n = n;
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
		sum.resize(n + 1);
	}

	int find(int x)
	{
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	void merge(int root, int u, int v)
	{
		u = find(u), v = find(v);
		sum[root] += sum[u] + sum[v];
		p[u] = p[v] = root;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	DSU dsu(2 * n);
	for(int i = 1; i <= n; i ++)
		cin >>dsu.sum[i];

	int tot = n;
	vector<array<int, 3>> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		edges[i] = {u, v, w};
	}

	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a[2] < b[2];
	});

	vector<vector<int>> adj(2 * n);
	vector<int> val(2 * n);
	for(auto [u, v, w] : edges)
	{
		u = dsu.find(u), v = dsu.find(v);
		if(dsu.same(u, v)) continue;
		val[++ tot] = w;
		adj[u].push_back(tot), adj[tot].push_back(u);
		adj[v].push_back(tot), adj[tot].push_back(v);
		dsu.merge(tot, u, v);
	}

	vector<int> dep(tot + 1);
	int len = __lg(tot) + 1;
	vector<array<int, 20>> f(tot + 1), need(tot + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa, need[u][0] = val[fa] - dsu.sum[u];
		for(int j = 1; j < len; j ++)
		{
			f[u][j] = f[f[u][j - 1]][j - 1];
			need[u][j] = max(need[u][j - 1], need[f[u][j - 1]][j - 1]);
		}

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u);
		}
	};
	dfs(tot, 0);

	auto lca = [&](int a, int b) -> int
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
	dsu.sum[0] = dsu.sum[tot];
	while(q --)
	{
		int x, k; cin >>x >>k;
		for(int j = len - 1; j >= 0; j --)
			if(k >= need[x][j])
				x = f[x][j];
		cout <<dsu.sum[x] + k <<endl;
	}
	return 0;
}
