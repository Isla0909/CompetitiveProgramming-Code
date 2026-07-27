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

struct Tree
{
	int n, len;
	vector<vector<int>> adj, f;
	vector<int> dep;

	Tree(int n)
	{
		this->n = n; 
		len = __lg(2 * n - 1);

		adj.resize(n + 1);
		f.resize(n + 1, vector<int>(len));
		dep.resize(n + 1);
	}

	void add(int a, int b)
	{
		adj[a].push_back(b);
	}

	void dfs(int u, int fa)
	{
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		for(int i = 1; i < len; i ++)
			f[u][i] = f[f[u][i - 1]][i - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);
		}
	}

	int lca(int a, int b)
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int k = len - 1; k >= 0; k --)
			if(dep[f[a][k]] >= dep[b])
				a = f[a][k];

		if(a == b) return a;

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

	int dist(int a, int b)
	{
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	}

	void work(int root = 1)
	{
		dfs(root, 0);
	}

	bool intersection(int a, int b, int c, int d) 
	{
		vector<int> v = {lca(a, c), lca(a, d), lca(b, c), lca(b, d)};
		sort(v.begin(), v.end(), [&](int i, int j) { return dep[i] > dep[j]; });

		int p1 = lca(a, b), p2 = lca(c, d);

		if(dep[v[0]] >= max(dep[p1], dep[p2])) return true;
		return false;
	}
};


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	Tree tr(n);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		tr.add(u, v), tr.add(v, u);
	}

	tr.work();

	while(q --)
	{
		int a, b, c, d; cin >>a >>b >>c >>d;
		cout <<(tr.intersection(a, b, c, d) ? "Y" : "N") <<endl;
	}

	return 0;
}