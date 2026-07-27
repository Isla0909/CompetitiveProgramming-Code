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
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	vector<int> siz(n + 1);
	auto dfs1 = [&](auto &&self, int u, int fa) -> void
	{
		siz[u] = 1;
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			self(self, v, u);
			siz[u] += siz[v];
		}
	};

	dfs1(dfs1, 1, -1);

	vector<vector<i64>> f(n + 1, vector<i64>(m + 1, -inf));
	auto dfs2 = [&](auto &&self, int u, int fa) -> void
	{
		f[u][0] = 0;
		if(m >= 1) f[u][1] = 0;

		int cur = 1;
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			self(self, v, u);

			vector<i64> nf(m + 1, -inf);
			for(int j = 0; j <= min(cur, m); j ++)
			{	
				if(f[u][j] == -inf) continue;
				for(int k = 0; k <= min(siz[v], m - j); k ++)
				{
					if(f[v][k] == -inf) continue;

					i64 s1 = 1LL * k * (m - k);
					int c1 = siz[v] - k, c2 = (n - m) - c1;
					i64 s2 = 1LL * c1 * c2;

					nf[j + k] = max(nf[j + k], f[u][j] + f[v][k] + 1LL * w * (s1 + s2));
				}
			}
			cur += siz[v];
			f[u].swap(nf);
		}
	};
	dfs2(dfs2, 1, -1);
	cout <<f[1][m] <<endl;
	return 0;
}
