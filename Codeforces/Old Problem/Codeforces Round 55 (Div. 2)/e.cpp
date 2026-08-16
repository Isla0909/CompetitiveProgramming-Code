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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	map<pii, int> mp; int idx = 0;
	vector<set<int>> s(k + 1);
	for(int i = 0; i < k; i ++)
	{
		int a, b, c; cin >>a >>b >>c;
		int id; pii t = {a, b};
		if(!mp.count(t)) mp[t] = ++ idx;
		id = mp[t];

		s[id].insert(c);
	}

	vector dist(n + 1, vector<int>(n + 1, INF));
	vector top(n + 1 , vector<pii>(n + 1, {-1, -1}));
	dist[1][0] = 0;
	queue<pii> q; q.emplace(1, 0);
	while(q.size())
	{
		auto [u, pre] = q.front(); q.pop();

		pii t = {pre, u}; 
		int f = mp.count(t);

		for(auto v : adj[u])
		{
			if(f && s[mp[t]].count(v)) continue;
			if(dist[v][u] > dist[u][pre] + 1)
			{
				dist[v][u] = dist[u][pre] + 1;
				top[v][u] = {u, pre};
				q.emplace(v, u);
			}
		}
	}
	int x = -1, mn = INF;
	for(int pre = 1; pre <= n; pre ++)
	{
		if(dist[n][pre] < mn)
		{
			x = pre;
			mn = dist[n][pre];
		}
	}
	if(mn == INF)
	{
		cout <<-1 <<endl;
		return 0;
	}

	vector<int> ans;
	pii t = {n, x};
	while(t.se != -1)
	{
		ans.push_back(t.ff);
		t = top[t.ff][t.se];
	}
	reverse(ans.begin(), ans.end());
	cout <<ans.size() - 1 <<endl;
	tell(0, ans);
	return 0;
}
