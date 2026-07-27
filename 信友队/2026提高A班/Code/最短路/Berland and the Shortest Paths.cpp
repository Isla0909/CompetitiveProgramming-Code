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
	vector<array<int, 2>> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i] = {u, v};
	}

	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	queue<int> q; q.emplace(1);
	while(q.size())
	{
		auto u = q.front(); q.pop();
		for(auto v : adj[u])
			if(dist[v] == INF)
			{
				dist[v] = dist[u] + 1;
				q.emplace(v);
			}
	}
	vector<vector<int>> pre(n + 1);
	for(int i = 0; i < m; i ++)
	{
		auto [u, v] = edges[i];
		if(dist[u] + 1 == dist[v])
			pre[v].push_back(i);
		if(dist[v] + 1 == dist[u])
			pre[u].push_back(i);
	}
	vector<string> ans;
	string s(m, '0');
	auto dfs = [&](auto &&self, int u) -> void
	{
		if(ans.size() == k) return ;

		if(u == n + 1)
		{
			ans.push_back(s);
			return ;
		}

		for(auto id : pre[u])
		{
			s[id] = '1';
			self(self, u + 1);
			s[id] = '0';
		}
	};
	dfs(dfs, 2);
	cout <<ans.size() <<endl;
	for(auto x : ans)
		cout <<x <<endl;
	return 0;
}
