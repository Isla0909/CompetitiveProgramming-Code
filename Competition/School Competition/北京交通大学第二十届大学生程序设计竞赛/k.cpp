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
	if(a.ff != b.ff) return a.ff < b.ff;
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
	}
	vector<vector<pii>> seg(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int k; cin >>k;
		for(int j = 0; j < k; j ++)
		{
			int l, r; cin >>l >>r;
			seg[i].emplace_back(l, r);
		}
		if(!k) continue;
		sort(seg[i].begin(), seg[i].end(), cmp);
		vector<pii> v;
		auto [L, R] = seg[i][0];
		for(int j = 1; j < seg[i].size(); j ++)
		{
			auto [l, r] = seg[i][j];
			if(l <= R + 1) R = max(R, r);
			else
			{
				v.emplace_back(L, R);
				L = l, R = r;
			}
		}
		v.emplace_back(L, R);
		seg[i] = v;
	}
	
	auto check = [&](int x, int u) -> pair<bool, int>
	{
		for(auto [l, r] : seg[u])
			if(x >= l && x <= r) return {true, r};
		return {false, -1};
	};

	vector<i64> dist(n + 1, inf);
	vector<int> st(n + 1);
	dist[1] = 0;
	priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
	q.emplace(0, 1);
	while(q.size())
	{
		auto [d, u] = q.top(); q.pop();
		if(st[u]) continue;
		st[u] = 1;
		for(auto [v, w] : adj[u])
		{
			auto [f, r] = check(d, u);
			if(f)
			{
				if(dist[v] > r + 1 + w)
				{
					dist[v] = r + 1 + w;
					q.emplace(dist[v], v);
				}
			}
			else
			{
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					q.emplace(dist[v], v);
				}
			}
		}
	}
	if(dist[n] == inf) cout <<-1 <<endl;
	else cout <<dist[n] <<endl;
	return 0;
}
