#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector f(n + 1, vector<ll>(2)); f[1][1] = a[1], f[1][0] = 0LL;
		function <void(int, int)> dfs = [&](int u, int fa) -> void
		{
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				f[v][1] = max(f[v][1], a[v] - f[u][0]);
				f[v][0] = min(0LL, a[v] - f[u][1]);

				dfs(v, u);
			}
		};
		dfs(1, -1);
		for(int i = 1; i <= n; i ++)
			cout <<f[i][1] <<" \n"[i == n];
	}
	return 0;
}