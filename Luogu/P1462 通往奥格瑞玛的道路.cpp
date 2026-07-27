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

	int n, m, b; cin >>n >>m >>b;
	vector<vector<pii>> adj(n + 1);
	vector<int> f(n + 1);
	for(int i = 1; i <= n; i ++) cin >>f[i];
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	auto dijkstra = [&](int s, int x) -> vector<i64>
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
				if(f[v] > x) continue;
				if(dist[v] > d + w)
				{
					dist[v] = d + w;
					q.emplace(dist[v], v);
				}
			}
		}
		return dist;
	};

	auto check = [&](int x) -> bool
	{
		if(f[1] > x) return false;
		auto dist = dijkstra(1, x);
		return dist[n] <= b;
	};

	if(!check(1e9))
	{
		cout <<"AFK" <<endl;
		return 0;
	}

	int l = -1, r = 1e9 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout <<r <<endl;
	return 0; 
}
