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
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	int len = __lg(n) + 1;
	vector f(n + 1, vector<int>(len));
	vector<int> dep(n + 1), eid(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		for(int j = 1; j < len; j ++)
			f[u][j] = f[f[u][j - 1]][j - 1];

		for(auto [v, id] : adj[u])
		{
			if(v == fa) continue;
			eid[v] = id;
			self(v, u);
		}
	};
	dfs(1, 0);

	auto lca = [&](int a, int b)
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int j = len - 1; j >= 0; j --)
			if(dep[f[a][j]] >= dep[b])
				a = f[a][j];

		if(a == b) return b;

		for(int j = len - 1; j >= 0; j --)
			if(f[a][j] != f[b][j])
			{
				a = f[a][j];
				b = f[b][j];
			}
		return f[a][0];
	};

	vector<int> d(n + 1), ans(n);
	int q; cin >>q;
	while(q --)
	{
		int u, v; cin >>u >>v;
		int p = lca(u, v);

		d[u] ++, d[v] ++;
		d[p] -= 2;
	}

	auto calc = [&](this auto &&self, int u, int fa) -> void
	{
		for(auto [v, id] : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
			d[u] += d[v];
			ans[id] = d[v];
		}
	};
	calc(1, 0);
	for(int i = 1; i < n; i ++)
		cout <<ans[i] <<" \n"[i == n - 1];
	return 0;
}
