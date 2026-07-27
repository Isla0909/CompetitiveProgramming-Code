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

	int n, m, q; cin >>n >>m >>q;
	vector<vector<pii>> g1(n + 1), g2(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, c, d; cin >>u >>v >>c >>d;
		g1[u].emplace_back(v, c);
		g2[v].emplace_back(u, d);
	}

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto dijkstra = [&](vector<vector<pii>> &adj, int s) -> vector<i64>
	{
		vector<i64> dist(n + 1, inf);
		vector<int> st(n + 1);
		priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
		dist[s] = 0; q.emplace(0, s);

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

	auto d1 = dijkstra(g1, 1), d2 = dijkstra(g2, n);

	auto calc = [&](int u) -> i64
	{
		return d1[u] + (d2[u] + a[u] - 1) / a[u];
	};

	set<pair<i64, int>> s;
	for(int i = 1; i <= n; i ++)
		s.insert({calc(i), i});

	while(q --)
	{
		int u, c; cin >>u >>c;
		s.erase({calc(u), u});

		a[u] = c;
		s.insert({calc(u), u});
		cout <<s.begin()->ff <<endl;
	}
	return 0;
}
