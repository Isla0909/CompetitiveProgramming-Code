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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, k; cin >>n >>m >>k;
	vector<int> adj[n + 1], dep(n + 1);
	vector<pii> edge(n);
	for(int i = 1; i < n; i ++)
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		edge[i] = {a, b};
	}

	vector<int> in(n + 1), out(n + 1); int cur = 0;
	vector f(n + 1, vector<int>(20));
	function <void(int, int)> dfs = [&](int u, int fa) -> void
	{
		in[u] = ++ cur;
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		for(int i = 1; i < 20; i ++)
			f[u][i] = f[f[u][i - 1]][i - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);
		}
		out[u] = cur;
	};
	dfs(1, 0);

	auto check = [&](int u, int v)
	{
		return in[u] <= in[v] && in[v] <= out[u];
	};

	auto lca = [&](int a, int b) -> i32
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int k = 19; k >= 0; k --)
			if(dep[f[a][k]] >= dep[b])
				a = f[a][k];

		if(a == b) return b;

		for(int k = 19; k >= 0; k --)
			if(f[a][k] != f[b][k])
			{
				a = f[a][k];
				b = f[b][k];
			}
		return f[a][0];
	};

	vector<int> id(m);
	for(int i = 0; i < m; i ++) cin >>id[i];

	unordered_map<int, int> mp;
	for(int i = 1; i <= k; i ++)
	{
		int u, v; cin >>u >>v;
		int c = 0;
		for(int j = 0; j < m; j ++)
		{
			bool f = 0; int x = id[j];
			int a = edge[x].ff, b = edge[x].se;

			if(dep[a] > dep[b]) swap(a, b);

			bool f1 = check(b, u), f2 = check(b, v);
			if(f1 != f2) f = 1;

			// if(dep[u] > dep[v]) swap(u, v);

			// int p1 = lca(u, v), p2 = lca(a, b);
			// int ua = lca(u, a), ub = lca(u, b), va = lca(v, a), vb = lca(v, b);
			// if(p1 == p2)
			// {
			// 	if(ua == a && vb == b) f = 1;
			// 	else if(va == a && ub == b) f = 1;
			// }
			// else
			// {
			// 	if(ua == u && vb == b) f = 1;
			// 	else if(lca(a, p1) == p1 && vb == b) f = 1;
			// 	else if(lca(a, p1) == p1 && ub == b) f = 1;
			// }
			// cout <<u <<" " <<v <<" " <<a <<" " <<b <<endl;
			// int ab_lca = lca(a, b), uv_lca = lca(u, v);
			// cout <<ab_lca <<" " <<uv_lca <<endl;
			if(f)
			{
				c |= (1 << j);
				//cout <<i <<" " <<j <<endl;
			}
		}
		if(c) mp[c] ++;
	}

	vector<int> dp(1 << m, INF); dp[0] = 0;
	vector<int> cnt(1 << m, 0); cnt[0] = 1;

	for(auto [x, c] : mp)
	{
		for(int s = (1 << m) - 1; s >= 0; s --)
		{
			if(dp[s] == INF) continue;

			int state = s | x;
			if(dp[state] > dp[s] + 1)
			{
				dp[state] = dp[s] + 1;
				cnt[state] = (1LL * cnt[s] * c) % mod;
			}
			else if(dp[state] == dp[s] + 1) cnt[state] = (cnt[state] + 1LL * cnt[s] * c) % mod;
		}
	}

	if(dp[(1 << m) - 1] == INF) cout <<-1 <<endl;
	else cout <<dp[(1 << m) - 1] <<" " <<cnt[(1 << m) - 1] <<endl;

	return 0;
}