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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		int len = __lg(2 * n - 1) + 1;
		vector<int> dep(n + 1), down(n + 1);
		vector f(n + 1, vector<int>(len)), val(n + 1, vector<int>(len, -INF));
		vector<int> mx1(n + 1), mx2(n + 1), son(n + 1);
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			dep[u] = dep[fa] + 1;
			down[u] = dep[u];
			mx1[u] = dep[u], mx2[u] = -INF, son[u] = 0;
			f[u][0] = fa;
			for(int k = 1; k < len; k ++)
				f[u][k] = f[f[u][k - 1]][k - 1];
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
				down[u] = max(down[u], down[v]);

				if(down[v] > mx1[u])
				{
					mx2[u] = mx1[u];
					mx1[u] = down[v];
					son[u] = v;
				}
				else if(down[v] > mx2[u]) mx2[u] = down[v];
			}
		};
		dfs(1, 0);
		for(int v = 2; v <= n; v ++)
		{
			int u = f[v][0];
			int best;
			if(son[u] == v) best = mx2[u];
			else best = mx1[u];

			val[v][0] = best - 2 * dep[u];
		}
		val[1][0] = -INF;
		for(int k = 1; k < len; k ++)
			for(int u = 1; u <= n; u ++)
				val[u][k] = max(val[u][k - 1], val[f[u][k - 1]][k - 1]);

		int q; cin >>q;
		for(int i = 1; i <= q; i ++)
		{
			int v, k; cin >>v >>k;
			int ans = down[v] - dep[v];

			int cur = v, best = -INF;
			for(int j = len - 1; j >= 0; j --)
			{
				if(k >> j & 1)
				{
					best = max(best, val[cur][j]);
					cur = f[cur][j];
				}
			}
			ans = max(ans, dep[v] + best);
			cout <<ans <<" \n"[i == q];
		}
	}
	return 0;
}
