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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<pii>> adj(n + 1);
	vector<array<int, 2>> edges(m);
	for(int i = 0; i < m; i ++)
		cin >>edges[i][0] >>edges[i][1];

	for(auto [u, v] : edges)
		adj[u].emplace_back(v, 0);

	vector<int> cnt(n + 1);
	auto dfs = [&](this auto &&self, int u, int e) -> void
	{
		cnt[u] ++;
		if(u == e) return ;
		for(auto [v, w] : adj[u])
		{
			if(e == n && !cnt[v] || e == 1 && cnt[v] == 1)
				self(v, e);
		}
	};

	auto clear = [&]() -> void
	{
		for(int i = 1; i <= n; i ++)
			adj[i].clear();
	};

	dfs(1, n);

	if(!cnt[n])
	{
		cout <<"No" <<endl;
		return 0;
	}

	clear();
	for(auto [u, v] : edges)
		adj[v].emplace_back(u, 1);
	dfs(n, 1);

	clear();
	for(auto [u, v] : edges)
	{
		if(cnt[u] == 2 && cnt[v] == 2)
		{
			adj[u].emplace_back(v, 2);
			adj[v].emplace_back(u, -1);
		}
	}
	vector<int> d(n + 1, INF); vector<bool> st(n + 1);
	vector<int> vis(n + 1);
	auto spfa = [&]() -> bool
	{
		d[1] = 0;
		queue<int> q; q.push(1); st[1] = 1;
		while(q.size())
		{
			auto u = q.front(); q.pop(); st[u] = 0;
			for(auto [v, w] : adj[u])
			{
				if(d[v] > d[u] + w)
				{
					d[v] = d[u] + w;
					vis[v] = vis[u] + 1;
					if(vis[v] >= n + 1) return false;

					if(!st[v])
					{
						q.push(v);
						st[v] = 1;
					}
				}
			}
		}
		return true;
	};

	if(spfa())
	{
		cout <<"Yes" <<endl;
		for(auto [u, v] : edges)
		{
			if(cnt[u] == 2 && cnt[v] == 2) cout <<abs(d[u] - d[v]) <<endl;
			else cout <<1 <<endl;
		}
	}
	else cout <<"No" <<endl;

	return 0;
}