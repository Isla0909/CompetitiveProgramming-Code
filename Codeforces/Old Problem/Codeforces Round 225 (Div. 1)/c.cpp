#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Fenwick
{
	#define lowbit(x) x & -x

	int n;
	vector<int> tr;

	Fenwick() {}
	Fenwick(int n)
	{
		initial(n);
	}

	void initial(int n)
	{
		this -> n = n;
		tr.assign(n + 1, 0);
	}

	void add(int x, int c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
 	}

 	int query(int x)
 	{
 		int res = 0;
 		for(int i = x; i; i -= lowbit(i))
 			res += tr[i];
 		return res;
 	}

 	void rangeAdd(int l, int r, int x)
 	{
 		add(l, x);
 		if(r + 1 <= n) add(r + 1, -x);
 	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> in(n + 1), seq(n + 1), siz(n + 1), dep(n + 1); int cur = 0;
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		in[u] = ++ cur, seq[in[u]] = u;
		siz[u] = 1, dep[u] = dep[fa] + 1;

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
			siz[u] += siz[v];
		}
	};
	dfs(1, 0);

	auto sign = [&](int u) -> int
	{
		return (dep[u] & 1) ? 1 : -1;
	};

	Fenwick bit(n);
	for(int i = 1; i <= n; i ++)
	{
		int left = seq[i - 1], now = seq[i];
		int x = a[left] * sign(left), y = a[now] * sign(now);
		bit.add(i, y - x);
	}

	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int u, delta; cin >>u >>delta;
			int l = in[u], r = in[u] + siz[u] - 1;
			bit.rangeAdd(l, r, delta * sign(u));
		}
		else
		{
			int u; cin >>u;
			cout <<bit.query(in[u]) * sign(u) <<endl;
		}
	}
	return 0;
}
