#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	i64 d;
	int u, s;
	bool operator>(const cxy &w) const
	{
		return d > w.d;
	}
	cxy(i64 d, int u, int s) : d(d), u(u), s(s) {}
};

void solve()
{
	int n, m, k, t; cin >>n >>m >>k >>t;
	vector dist(n + 1, vector<i64>(1 << k, inf));
	vector vis(n + 1, vector<bool>(1 << k));
	unordered_map<int, vector<int>> mp;
	vector<vector<pii>> adj(n + 1);
	while(m --)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	unordered_map<int, int> id;
	for(int i = 1; i <= k; i ++)
	{
		int x; cin >>x;
		id[x] = i - 1;
	}

	for(int i = 0; i < t; i ++)
	{
		int x, y; cin >>x >>y;
		mp[y].push_back(x);
	}

	priority_queue <cxy, vector<cxy>, greater<cxy>> q;
	q.emplace(0, 1, 0);
	while(q.size())
	{
		auto [d, u, s] = q.top(); q.pop();
		//cout <<d <<" " <<u <<" " <<s <<endl;
		if(vis[u][s]) continue;
		vis[u][s] = 1;

		if(u == n)
		{
			cout <<d <<endl;
			return ;
		}

		for(auto [v, w] : adj[u])
		{
			if(mp.count(v))
			{
				bool f = 1;
				for(auto need : mp[v])
				{
					if((s >> id[need] & 1) == 0)
					{
						f = 0;
						break;
					}
				}
				if(!f) continue;
				if(id.count(v)) 
				{
					int bit = id[v];
					if(dist[v][s | (1 << bit)] > d + w)
					{
						dist[v][s | (1 << bit)] = d + w;
						q.emplace(d + w, v, s | (1 << bit));
						//cout <<"s : " <<(s | (1 << bit)) <<" " <<" u and v " <<u <<" " <<v <<" " <<d + w <<endl;
					}
				}
				else if(dist[v][s] > d + w)
				{
					dist[v][s] = d + w;
					q.emplace(d + w, v, s);
					//cout <<"s : " <<s <<" " <<" u and v " <<u <<" " <<v <<" " <<d + w <<endl;
				}
				continue;
			}
			if(id.count(v)) 
			{
				int bit = id[v];
				if(dist[v][s | (1 << bit)] > d + w)
				{
					dist[v][s | (1 << bit)] = d + w;
					q.emplace(d + w, v, s | (1 << bit));
					//cout <<"s: " <<(s | (1 << bit)) <<" " <<" u and v " <<u <<" " <<v <<" " <<d + w <<endl;
				}
			}
			else
			{
				if(dist[v][s] > d + w)
				{
					dist[v][s] = d + w;
					q.emplace(d + w, v, s);
					//cout <<"s : " <<s <<" " <<" u and v " <<u <<" " <<v <<" " <<d + w <<endl;
				}
			}
		}
	}
	cout <<"impossible" <<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}
	return 0;
}