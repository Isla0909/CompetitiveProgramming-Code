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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
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

	int n, m, k; cin >>n >>m >>k;
	vector<vector<pii>> adj(n + 1);
	vector<array<int, 3>> edges(m + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges[i] = {u, v, w};
	}

	auto dijkstra = [&](int s) -> vector<i64>
	{
		vector<i64> dist(n + 1, inf);
		vector<bool> st(n + 1);
		priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
		q.emplace(0, s); dist[s] = 0;
		while(q.size())
		{
			auto [d, u] = q.top(); q.pop();
			if(st[u]) continue;
			st[u] = 1;

			for(auto [v, w] : adj[u])
			{
				if(dist[v] > d + w)
				{
					dist[v] = d + w;
					q.emplace(dist[v], v);
				}
			}
		}
		return dist;
	};

	auto dist = dijkstra(1);

	vector<vector<pii>> top(n + 1);
	for(int i = 0; i < m; i ++)
	{
		auto [u, v, w] = edges[i];
		if(dist[v] + w == dist[u]) top[v].emplace_back(u, i + 1);
		if(dist[u] + w == dist[v]) top[u].emplace_back(v, i + 1);
	}

	vector<int> ans;
	queue<int> q; q.emplace(1);
	vector<int> st(n + 1); st[1] = 1;
	while(q.size())
	{
		auto u = q.front(); q.pop();
		for(auto [v, id] : top[u])
		{
			if(!st[v])
			{
				st[v] = 1;
				ans.push_back(id);
				q.emplace(v);
			}
		}
	}
	int r = min(k, (int)ans.size());
	cout <<r <<endl;
	for(int i = 0; i < r; i ++)
		cout <<ans[i] <<" \n"[i == r - 1];
	return 0;
}
