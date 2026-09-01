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

	int n, m, s; cin >>n >>m >>s;
	vector<vector<pii>> adj1(n + 1), adj2(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj1[u].emplace_back(v, w);
		adj2[v].emplace_back(u, w);
	}

	auto dijkstra = [&](int s, vector<vector<pii>> &adj) -> vector<int>
	{
		vector<int> dist(n + 1, INF), st(n + 1);
		dist[s] = 0;
		priority_queue<pii, vector<pii>, greater<>> q;
		q.emplace(0, s);
		while(q.size())
		{
			auto [d, u] = q.top(); q.pop();

			if(st[u]) continue;
			st[u] = true;

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

	auto d1 = dijkstra(s, adj1), d2 = dijkstra(s, adj2);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, d1[i] + d2[i]);
	cout <<ans <<endl;
	return 0;
}
