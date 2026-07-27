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

	Tree(int n)
	{
		this->n = n;
		len = __lg(2 * n - 1);
		adj.resize(n + 1);
		f.resize(n + 1, vector<int>(len));
		dep.resize(n + 1);
		dist.resize(n + 1);
	}

	void add(int a, int b, int w)
	{
		adj[a].emplace_back(b, w);
	}

	void dfs(int u, int fa)
	{
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		for(int i = 1; i < len; i ++)
			f[u][i] = f[f[u][i - 1]][i - 1];

		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			dist[v] = dist[u] + w;
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

	i64 dis(int a, int b)
	{
		return dist[a] + dist[b] - 2 * dist[lca(a, b)];
	}

	void work(int root = 1)
	{
		dfs(root, 0);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> cost(n + 1), d(n + 1);
	for(int i = 1; i <= n; i ++) cin >>cost[i];
	for(int i = 1; i <= n; i ++) cin >>d[i];

	Tree tr(n);
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		tr.add(u, v, w), tr.add(v, u, w);
	}

	tr.work();

	vector<vector<int>> dis(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			dis[i][j] = dis[j][i] = tr.dis(i, j);

	vector<vector<int>> f(n + 1, vector<int>(n + 1, INF));
	vector<int> g(n + 1, INF);
	auto dfs = [&](auto &&self, int u, int fa) -> void
	{
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			self(self, v, u);
		}

		for(int j = 1; j <= n; j ++)
		{
			if(dis[u][j] > d[u]) continue;

			int res = cost[j];
			for(auto [v, w] : adj[u])
			{
				if(v == fa) continue;

				int val = g[v];
				if(f[v][j] != INF) val = min(val, f[v][j] - cost[j]);
				else res += val;
			}
			f[u][j] = res;
		}
		for(int j = 1; j <= n; j ++)
			g[u] = min(g[u], f[u][j]);
	};
	dfs(dfs, 1, -1);
	cout <<g[1] <<endl;
	return 0;
}
