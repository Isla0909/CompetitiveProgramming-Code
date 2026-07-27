#include <bits/stdc++.h>
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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		i64 ans = 1LL * n * (n - 1) / 2 - (n - 1);
		
		auto bfs = [&](int u) -> i32
		{
			unordered_map<int, int> mp;

			int res = 0;
			queue<int> q; q.push(u); mp[u] = 1;
			while(q.size())
			{
				auto t = q.front(); q.pop();
				for(auto v : adj[t])
				{
					if(!mp[v])
					{
						mp[v] = mp[t] + 1;
						if(mp[v] < 4) q.push(v);
						else if(adj[v].size() == 1) res ++;
					}
				}
			}
			return res;
		};

		vector<int> fa(n + 1); fa[1] = 0;
		vector<int> dep(n + 1); dep[1] = 1;
		vector<int> h(n + 1);
		function <void(int, int)> dfs = [&](int u, int p) -> void
		{
			fa[u] = p;
			for(auto v : adj[u])
			{
				if(v == p) continue;
				dep[v] = dep[u] + 1;
				if(adj[v].size() == 1) h[dep[v]] ++;
				dfs(v, u);
			}
		};
		dfs(1, 0);

		vector<int> cnt(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			for(auto v : adj[i])
			{
				if(v != fa[i] && adj[v].size() == 1) cnt[i] ++;
			}
		}

		for(int i = 1; i <= n; i ++)
		{
			if(adj[i].size() == 1)
			{
				int p = fa[i];
				if(p == 0) continue;

				//cout <<p <<" " <<cnt[p] <<endl;
				ans -= cnt[fa[p]];

				//out <<i <<" " <<ans <<endl;
				p = fa[p];
				p = fa[p];
				
				if(adj[p].size() == 1) ans --;

				//cout <<i <<" " <<ans <<endl;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}