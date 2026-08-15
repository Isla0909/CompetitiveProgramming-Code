#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> col(n + 1);
	for(int i = 1; i <= n; i ++) cin >>col[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> siz(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		siz[u] = 1;
		if(fa != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa));
		for(auto &v : adj[u])
		{
			self(v, u);
			siz[u] += siz[v];
			if(siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
		}
	};
	dfs(1, -1);

	vector<int> cnt(n + 1);
	vector<i64> sum(n + 1), ans(n + 1);
	sum[0] = 1LL * (1 + n) * n / 2;
	int M = 0;

	auto addv = [&](int col, int c) -> void
	{
		sum[cnt[col]] -= col;
		cnt[col] += c;
		M = max(M, cnt[col]);
		sum[cnt[col]] += col;

		while(M >= 0 && !sum[M]) M --;
	};

	auto add = [&](this auto &&self, int u, int c) -> void
	{
		addv(col[u], c);
		for(auto v : adj[u])
			self(v, c);
	};

	auto calc = [&](this auto &&self, int u) -> void
	{
		for(auto v : adj[u])
		{
			if(v == adj[u][0]) continue;
			self(v);
			add(v, -1);
		}

		if(adj[u].size())
		{
			self(adj[u][0]);
			for(auto v : adj[u])
			{
				if(v == adj[u][0]) continue;
				add(v, 1);
			}
		}
		addv(col[u], 1);
		ans[u] = sum[M];
	};
	calc(1);
	for(int i = 1; i <= n; i ++)
		cout <<ans[i] <<" \n"[i == n];
	return 0;
}
