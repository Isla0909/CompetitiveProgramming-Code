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
	vector<array<int, 3>> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges[i] = {u, v, w};
	}

	vector<int> cnt(n + 1);
	for(int i = 0; i < k; i ++)
	{
		int u, w; cin >>u >>w;
		adj[1].emplace_back(u, w);
		adj[u].emplace_back(1, w);
		cnt[u] ++;
	}

	vector<i64> d(n + 1, inf);
	vector<int> st(n + 1);
	priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
	d[1] = 0; q.emplace(0, 1);
	while(q.size())
	{
		auto [x, u] = q.top(); q.pop();

		if(st[u]) continue;
		st[u] = 1;

		for(auto [v, w] : adj[u])
		{
			if(d[v] > x + w)
			{
				d[v] = x + w;
				q.emplace(d[v], v);
			}
		}
	} 

	vector<int> in(n + 1);
	for(auto [u, v, w] : edges)
	{
		if(d[u] == d[v] + w) in[u] ++;
		if(d[v] == d[u] + w) in[v] ++;
	}
	int ans = 0;
	for(int i = 2; i <= n; i ++)
	{
		if(!cnt[i]) continue;
		if(!in[i]) ans ++;
	}
	cout <<k - ans <<endl;
	return 0;
}
