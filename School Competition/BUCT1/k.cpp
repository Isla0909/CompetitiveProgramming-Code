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

	int n, m, x, y; cin >>n >>m >>x >>y;
	vector<vector<pii>> adj(n + 1);
	while(m --)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	auto dijkstra = [&](int s) -> vector<i64>
	{
		vector<i64> dist(n + 1, inf);
		vector<int> st(n + 1);
		priority_queue<pii, vector<pii>, greater<pii>> q;
		dist[s] = 0; q.emplace(0, 1);
		while(q.size())
		{
			auto [d, u] = q.top(); q.pop();

			if(st[u]) continue;
			st[u] = 1;

			for(auto [v, w] : adj[u])
			{
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					q.emplace(dist[v], v);
				}
			}
		}
		return dist;
	};

	auto dx = dijkstra(x), dy = dijkstra(y);
	set<int> s;
	for(int i = 1; i <= n; i ++)
	{
		if(dx[i] + dy[i] == dx[n])
			s.insert(i);
	}

	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			if(!s.count(i) && !s.count(j)) continue;
			else
			{
				auto d = dijkstra(i);
				if(dx[i] + d[j] + dy[j] != dx[n] && dx[j] + d[j] + dy[i] != dx[n]) ans ++; 
			}
		}
	}
	cout <<ans <<endl;
	return 0;
}
