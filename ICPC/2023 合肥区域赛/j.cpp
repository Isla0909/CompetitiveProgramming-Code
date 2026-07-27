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
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	vector<int> d1(n + 1, INF); d1[1] = 0;
	vector<bool> st(n + 1);
	priority_queue<pii, vector<pii>, greater<pii>> q; q.emplace(0, 1);
	while(q.size())
	{
		auto [d, u] = q.top(); q.pop();
		if(st[u]) continue;
		st[u] = 1;

		for(auto [v, w] : adj[u])
		{
			if(st[v] || max(d, w) >= d1[v]) continue;
			d1[v] = max(d, w);
			q.emplace(d1[v], v);
		}
	}
	vector<int> d2(n + 1, INF); d2[n] = 0;
	fill(st.begin(), st.end(), false); q.emplace(0, n);
	while(q.size())
	{
		auto [d, u] = q.top(); q.pop();

		if(st[u]) continue;
		st[u] = 1;

		for(auto [v, w] : adj[u])
		{
			if(st[v] || max(d, w) >= d2[v]) continue;
			d2[v] = max(d, w);
			q.emplace(d2[v], v);
		}
	}
	int ans = 2e9;
	for(int u = 1; u <= n; u ++)
		for(auto [v, w] : adj[u])
		{
			if(w >= d1[u] && w >= d2[v])
				ans = min(ans, w + max(d1[u], d2[v]));
			if(w >= d1[v] && w >= d2[u])
				ans = min(ans, w + max(d1[v], d2[u]));
		}
	cout <<ans <<endl;
	return 0;
}