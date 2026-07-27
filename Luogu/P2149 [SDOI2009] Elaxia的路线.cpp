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
	int s1, s2, s3, s4; cin >>s1 >>s2 >>s3 >>s4;
	vector<vector<pii>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
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

	vector<i64> d1 = dijkstra(s1), d2 = dijkstra(s2), d3 = dijkstra(s3), d4 = dijkstra(s4);
	i64 dist1 = d1[s2], dist2 = d3[s4];
	auto solve = [&](vector<i64> &l, vector<i64> &r) -> i64
	{
		i64 res = 0;
		vector<int> p(n + 1);
		iota(p.begin(), p.end(), 0);
		sort(p.begin() + 1, p.end(), [&](auto a, auto b)
		{
			return d1[a] < d1[b];
		});

		vector<i64> f(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int u = p[i];
			for(auto [v, w] : adj[u])
			{
				if(d1[u] + w + d2[v] == dist1 && l[u] + w + r[v] == dist2)
				{
					f[v] = max(f[v], f[u] + w);
					res = max(res, f[v]);
				}
			}
		}
		return res;
	};
	cout <<max(solve(d3, d4), solve(d4, d3)) <<endl;
	return 0;
}