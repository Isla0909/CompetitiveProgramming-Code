#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

constexpr i64 inf = 1e18;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adj(n + 1);
	vector<int> deg(n + 1);

	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].emplace_back(v, w);
		deg[v]++;
	}

	queue<int> q;
	vector<int> top;

	for(int i = 1; i <= n; i++)
		if(deg[i] == 0)
			q.emplace(i);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		top.push_back(u);

		for(auto [v, w] : adj[u])
		{
			deg[v]--;

			if(deg[v] == 0)
				q.emplace(v);
		}
	}

	vector<i64> f(n + 1, -inf);
	f[1] = 0;

	for(int u : top)
	{
		if(f[u] == -inf)
			continue;

		for(auto [v, w] : adj[u])
			f[v] = max(f[v], f[u] + w);
	}

	vector<i64> g(n + 1, -inf);
	g[n] = 0;

	for(int i = n - 1; i >= 0; i--)
	{
		int u = top[i];

		for(auto [v, w] : adj[u])
		{
			if(g[v] != -inf)
				g[u] = max(g[u], g[v] + w);
		}
	}

	int ans = 0;

	for(int u = 1; u <= n; u++)
	{
		if(f[u] != -inf && g[u] != -inf && f[u] + g[u] == f[n])
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}