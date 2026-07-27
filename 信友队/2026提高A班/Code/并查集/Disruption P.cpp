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

struct Tree
{
	int n, len;
	vector<vector<pii>> adj;
	vector<vector<int>> f;
	vector<int> dep;
	vector<i64> dist;
	vector<int> to;

	Tree(int n)
	{
		this->n = n;
		len = __lg(2 * n - 1);
		adj.resize(n + 1);
		f.resize(n + 1, vector<int>(len));
		dep.resize(n + 1);
		to.resize(n + 1);
	}

	void add(int a, int b, int id)
	{
		adj[a].emplace_back(b, id);
	}

	void dfs(int u, int fa)
	{
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		for(int i = 1; i < len; i ++)
			f[u][i] = f[f[u][i - 1]][i - 1];

		for(auto [v, id] : adj[u])
		{
			if(v == fa) continue;

			to[v] = id;
			dfs(v, u);
		}
	}

	int lca(int a, int b)
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int k = len - 1; k >= 0; k --)
		{
			if(dep[f[a][k]] >= dep[b])
				a = f[a][k];
		}

		if(a == b) return b;
		for(int k = len - 1; k >= 0; k --)
		{
			if(f[a][k] != f[b][k])
			{
				a = f[a][k];
				b = f[b][k];
			}
		}
		return f[a][0];
	}

	void work(int root = 1)
	{
		dfs(root, 0);
	}

	auto get_dep()
	{
		return dep;
	}
};

struct DSU
{
	vector<int> p, siz;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);
	}

	DSU(int n)
	{
		initial(n);
	}

	int find(int x)
	{
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	void erase(int x, int fa)
	{
		p[x] = find(fa);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	Tree tr(n);

	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		tr.add(u, v, i);
		tr.add(v, u, i);
	}
	tr.work();

	vector<array<int, 3>> edges;
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		edges.push_back({u, v, w});
	}

	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a[2] < b[2];
	});

	DSU dsu(n);
	vector<int> ans(n, -1);
	auto dep = tr.get_dep();
	for(auto [u, v, w] : edges)
	{
		int p = tr.lca(u, v);
		while(dep[dsu.find(u)] > dep[p])
		{
			int pu = dsu.find(u);
			ans[tr.to[pu]] = w;
			dsu.erase(pu, tr.f[pu][0]);
		}
		while(dep[dsu.find(v)] > dep[p])
		{
			int pv = dsu.find(v);
			ans[tr.to[pv]] = w;
			dsu.erase(pv, tr.f[pv][0]);
		}
	}
	for(int i = 1; i < n; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
