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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	vector<i64> a(n + 1), f(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<pair<int, i64>>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<int> b(q + 1);;
	for(int i = 1; i <= q; i ++) cin >>b[i];

	for(int u = 1; u <= n; u ++)
	{
		sort(adj[u].begin(), adj[u].end());

		vector<pair<int, i64>> h;
		for(auto [v, w] : adj[u])
			if(!h.size() || h.back().ff != v)
				h.emplace_back(v, w);
		adj[u] = move(h);
	}

	int B = max(1, (int)sqrt(m));
	vector<int> big;
	for(int u = 1; u <= n; u ++)
		if(adj[u].size() > B + 1)
			big.push_back(u);

	for(int r = q; r >= 1; r -= B)
	{
		int l = max(1, r - B + 1);
		for(auto u : big)
			nth_element(adj[u].begin(), adj[u].begin() + B + 1, adj[u].end(), [&](auto &a, auto &b)
			{
				return f[a.ff] + a.se < f[b.ff] + b.se;
			});

		for(int t = r; t >= l; t --)
		{
			int u = b[t];
			int len = min((int)adj[u].size(), B + 1);
			i64 res = inf;
			for(int j = 0; j < len; j ++)
			{
				auto [v, w] = adj[u][j];
				res = min(res, f[v] + w);
			}
			f[u] = res;
		}
	}
	i64 ans = 0;
	for(int u = 1; u <= n; u ++)
		ans = (ans + (a[u] % mod) * f[u] % mod) % mod;
	cout <<ans <<endl;
	return 0;
}
