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

	bool intersection(int a, int b, int c, int d)//a - b, c - d 路径上是否存在交点 
	{
		vector<int> v = {lca(a, c), lca(a, d), lca(b, c), lca(b, d)};
		sort(v.begin(), v.end(), [&](int i, int j) { return dep[i] > dep[j]; });

		int p1 = lca(a, b), p2 = lca(c, d);

		if(dep[v[0]] >= max(dep[p1], dep[p2])) return true;
		return false;
	}
};
//注: 记得调用work函数!!!

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	Tree tr(n);
	for(int i = 0; i < n - 1; i ++)
	{
		int u, v; cin >>u >>v;
		tr.add(u, v), tr.add(v, u);
	}
	tr.work();

	vector<i64> s(n + 1);
	while(m --)
	{
		int u, v; cin >>u >>v;
		int p = tr.lca(u, v);
		s[u] ++, s[v] ++, s[p] --, s[tr.f[p][0]] --;
	}

	function<void(int, int)> dfs = [&](int u, int fa) -> void
	{
		for(auto v : tr.adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);

			s[u] += s[v];
		}
	};
	dfs(1, 0);
	for(int i = 1; i <= n; i ++)
		cout <<s[i] <<" \n"[i == n];
	return 0;
}
