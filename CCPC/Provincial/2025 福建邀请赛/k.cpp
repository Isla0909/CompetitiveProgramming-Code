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

	int n; cin >>n;
	vector<pii> adj[n + 1];
	for(int i = 1; i < n; i ++)
	{
		int a, b, c; cin >>a >>b >>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<int> l(n + 1, 1), r(n + 1, INF);
	function <void(int, int)> dfs;
	dfs = [&](int u, int fa) -> void
	{
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			r[v] = min(r[v], w);
			dfs(v, u);

			r[u] = min(r[u], w - l[v]);
			l[u] = max(l[u], w - r[v]);
		}
	};

	dfs(1, -1);
	bool f = 1;
	for(int i = 1; i <= n; i ++)
		if(l[i] > r[i])
		{
			f = 0;
			break;
		}

	if(!f) cout <<"NO" <<endl;
	else
	{
		cout <<"YES" <<endl;
		vector<int> w(n + 1); w[1] = l[1];
		vector<int> st(n + 1);
		queue<int> q; q.push(1);
		while(q.size())
		{
			auto t = q.front(); q.pop();
			st[t] = 1;
			for(auto [b, c] : adj[t])
			{
				if(st[b]) continue;
				w[b] = c - w[t];
				st[b] = 1;
				q.push(b);
			}
		}
		for(int i = 1; i <= n; i ++)
			cout <<w[i] <<" \n"[i == n];
	}
	return 0;
}