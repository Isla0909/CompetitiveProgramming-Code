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
	vector d(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n - 1; i ++)
		for(int j = i + 1; j <= n; j ++)
		{
			int x; cin >>x;
			d[i][j] = d[j][i] = x;
		}
	vector<vector<int>> v(n + 1);
	for(int i = 2; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(j != i && d[i][j] + d[j][1] == d[i][1]) v[i].push_back(j);

	bool f = 1; Tree tr(n);
	for(int i = 2; i <= n; i ++)
	{
		if(!v[i].size())
		{
			f = 0;
			break;
		}
		sort(v[i].begin(), v[i].end(), [&](auto a, auto b)
		{
			return d[i][a] < d[i][b];
		});
		int p = v[i][0];
		tr.add(i, p, d[i][p]);
		tr.add(p, i, d[i][p]);
	}
	if(!f)
	{
		cout <<"No" <<endl;
		return 0;
	}

	tr.work();
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(d[i][j] != tr.dis(i, j)) f = 0;
	cout <<(f ? "Yes" : "No") <<endl;
	return 0;
}
