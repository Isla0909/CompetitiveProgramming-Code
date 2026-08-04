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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<array<int, 4>> edges;
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		edges.push_back({u, v, w, i});
	}

	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);

	auto find = [&](this auto &&self, int x) -> int
	{
		if(x != p[x]) p[x] = self(p[x]);
		return p[x];
	};

	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a[2] < b[2];
	});

	vector<vector<pii>> adj(n + 1);
	vector<bool> st(m);
	i64 sum = 0;
	for(auto [u, v, w, id] : edges)
	{
		int pu = find(u), pv = find(v);
		if(pu == pv) continue;

		p[pu] = pv;
		sum += w;
		st[id] = true;

		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	int len = __lg(n) + 1;
	vector f(n + 1, vector<int>(len)), M(n + 1, vector<int>(len));
	vector<int> dep(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa, int w) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa, M[u][0] = w;

		for(int i = 1; i < len; i ++)
		{
			f[u][i] = f[f[u][i - 1]][i - 1];
			M[u][i] = max(M[u][i - 1], M[f[u][i - 1]][i - 1]);
		}

		for(int i = 1; i < len; i ++)
			f[u][i] = f[f[u][i - 1]][i - 1];

		for(auto [v, nw] : adj[u])
		{
			if(v == fa) continue;

			self(v, u, nw);
		}
	};
	dfs(1, 0, 0);
	auto get = [&](int a, int b) -> int
	{
		if(dep[a] < dep[b]) swap(a, b);

		int res = 0;
		for(int i = len - 1; i >= 0; i --)
			if(dep[f[a][i]] >= dep[b])
			{
				res = max(res, M[a][i]);
				a = f[a][i];
			}
		if(a == b) return res;

		for(int i = len - 1; i >= 0; i --)
			if(f[a][i] != f[b][i])
			{
				res = max(res, M[a][i]), a = f[a][i];
				res = max(res, M[b][i]), b = f[b][i];
			}
		return max({res, M[a][0], M[b][0]});
	};

	vector<i64> ans(m); 
	for(auto [u, v, w, id] : edges)
	{
		if(st[id]) ans[id] = sum;
		else ans[id] = sum + w - get(u, v);
	}
	for(int i = 0; i < m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
