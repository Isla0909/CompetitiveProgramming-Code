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

	int n; cin >>n;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dep(n + 1), f(n + 1);
	auto dfs1 = [&](this auto &&self, int u, int fa) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u] = dep[u];
		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u);
			f[u] = max(f[u], f[v]);
		}
	};

	dfs1(1, 0);

	int q; cin >>q;
	vector<vector<pii>> task(n + 1);
	while(q --)
	{
		int u, d, add; cin >>u >>d >>add;
		task[u].emplace_back(d, add);
	}

	vector<i64> ans(n + 1), add(n + 1); i64 pre = 0;
	auto dfs2 = [&](this auto &&self, int u, int fa) -> void
	{
		for(auto [d, x] : task[u])
		{
			int l = dep[u], r = min(f[u], l + d);
			add[l] += x;
			if(r + 1 <= n) add[r + 1] -= x;
		}

		pre += add[dep[u]];
		ans[u] = pre;

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u);
		}

		pre -= add[dep[u]];
		for(auto [d, x] : task[u])
		{
			int l = dep[u], r = min(f[u], l + d);
			add[l] -= x;
			if(r + 1 <= n) add[r + 1] += x;
		}
	};
	dfs2(1, -1);

	for(int i = 1; i <= n; i ++)
		cout <<ans[i] <<" \n"[i == n];
	return 0;
}
