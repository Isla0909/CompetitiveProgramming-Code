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
	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		deg[u] ++, deg[v] ++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(deg[i] == 1)
			q.emplace(i);

	while(q.size())
	{
		auto u = q.front(); q.pop();
		deg[u] --;
		for(auto v : adj[u])
		{
			deg[v] --;
			if(deg[v] == 1) q.emplace(v);
		}
	}



	int ans = 0;
	vector<int> st(n + 1); int idx = 1;

	bool f = 1;
	auto dfs = [&](this auto &&self, int u) -> void
	{
		st[u] = idx;
		if(adj[u].size() != 2) f = 0;

		for(auto v : adj[u])
			if(!st[v]) self(v);
	};

	for(int i = 1; i <= n; i ++)
	{
		if(!deg[i] || st[i]) continue;

		f = 1;
		dfs(i);
		idx ++;
		if(f) ans ++;
	}
	cout <<ans <<endl;
	return 0;
}
