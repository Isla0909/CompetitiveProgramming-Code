## Trie树合并

```c++
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
constexpr long long inf = 1e18;

constexpr int N = 2e5 + 10, M = 32 * N, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int trie[M][2];
int mn[M];
int tot;

int newNode()
{
	tot ++;
	trie[tot][0] = trie[tot][1] = 0;
	mn[tot] = INF;
	return tot;
}

void insert(int &root, int x, int time)
{
	if(!root) root = newNode();

	int p = root;
	mn[p] = min(mn[p], time);

	for(int i = 30; i >= 0; i --)
	{
		int d = x >> i & 1;

		if(!trie[p][d]) trie[p][d] = newNode();

		p = trie[p][d];
		mn[p] = min(mn[p], time);
	}
}

int merge(int x, int y)
{
	if(!x || !y) return x + y;

	mn[x] = min(mn[x], mn[y]);
	trie[x][0] = merge(trie[x][0], trie[y][0]);
	trie[x][1] = merge(trie[x][1], trie[y][1]);

	return x;
}

int max_query(int root, int x, int time)
{
	int p = root, res = 0;
	for(int i = 30; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(trie[p][d ^ 1] && mn[trie[p][d ^ 1]] <= time)
		{
			p = trie[p][d ^ 1];
			res |= 1 << i;
		}
		else p = trie[p][d];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >>q;
	int now = 1;
	vector<int> dist(q + 2), t(q + 2, INF);
	t[1] = 0;

	vector<vector<int>> adj(q + 2);
	vector<vector<array<int, 3>>> query(q + 2);
	int id = 0;
	for(int i = 1; i <= q; i ++)
	{
		string op; cin >>op;
		if(op == "Add")
		{
			int u, w; cin >>u >>w;
			dist[++ now] = dist[u] ^ w;
			t[now] = i;

			adj[u].push_back(now);
			adj[now].push_back(u);
		}
		else
		{	
			int a, b; cin >>a >>b;
			query[b].push_back({a, i, ++ id});
		}
	}

	vector<int> root(q + 2);
	for(int u = 1; u <= now; u ++)
		insert(root[u], dist[u], t[u]);

	vector<int> ans(id + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);

			root[u] = merge(root[u], root[v]);
		}

		for(auto [a, time, id] : query[u])
		{
			ans[id] = max_query(root[u], dist[a], time);
		}
	};
	dfs(1, 0);

	for(int i = 1; i <= id; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
```

