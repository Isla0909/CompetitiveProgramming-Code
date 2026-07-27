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

	int n, m; cin >>n >>m;
	vector<array<int, 3>> edges(m);
	vector<vector<pii>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges[i] = {u, v, w};
	}

	int s; cin >>s;
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

	auto dist = dijkstra(s);

	// for(int i = 1; i <= n; i ++)
	// 	cout <<dist[i] <<" \n"[i == n];

	vector<int> pre(n + 1, -1);
	for(int i = 0; i < m; i ++)
	{
		auto [u, v, w] = edges[i];
		if(dist[u] + w == dist[v])
		{
			if(pre[v] == -1 || w < edges[pre[v]][2]) pre[v] = i;
		}
		if(dist[v] + w == dist[u])
		{ 
			if(pre[u] == -1 || w < edges[pre[u]][2]) pre[u] = i;
		}
	}
	vector<int> ans; i64 sum = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(i == s) continue;
		sum += edges[pre[i]][2];
		ans.push_back(pre[i] + 1);
	}
	cout <<sum <<endl;
	tell(0, ans);
	return 0;	
}
