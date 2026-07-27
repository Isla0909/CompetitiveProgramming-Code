#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

struct cxy
{
	int c, r, id;
	bool operator>(const cxy &T) const
	{
		if(c != T.c) return c > T.c;
		return r > T.r;
	}
	cxy (int c, int r, int id) : c(c), r(r), id(id) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, V, s; cin >>n >>m >>V >>s;
	vector<vector<pii>> adj(n + 1);
	while(m --)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<bool> st(n + 1);
	vector<pii> d(n + 1, {INF, V}); d[s] = {1, 0};
	priority_queue<cxy, vector<cxy>, greater<>> q;
	q.emplace(1, 0, s);
	while(q.size())
	{
		auto [c, r, u] = q.top(); q.pop();
		if(st[u]) continue;
		st[u] = 1;

		for(auto [v, w] : adj[u])
		{
			int cv, rv;
			if(r + w > V) cv = c + 1, rv = w;
			else cv = c, rv = r + w;

			if(d[v].ff > cv || d[v].ff == cv && d[v].se > rv)
			{
				d[v] = {cv, rv};
				q.emplace(cv, rv, v);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(d[i].ff == INF) cout <<-1 <<" ";
		else cout <<d[i].ff <<" ";
	}
	cout <<endl;
	return 0;
}