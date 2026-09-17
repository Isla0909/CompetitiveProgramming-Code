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

	vector<int> dep(n + 1), dfn(n + 1); int cur = 0;
	vector<array<int, 20>> f(n + 1);
	[&](this auto &&self, int u, int fa) -> void
	{
		dfn[u] = ++ cur;
		dep[u] = dep[fa] + 1;
		f[u][0] = fa;

		for(int j = 1; j < 20; j ++)
			f[u][j] = f[f[u][j - 1]][j - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
		}
	}(1, 0);

	auto lca = [&](int a, int b) -> int
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int j = 19; j >= 0; j --)
			if(dep[f[a][j]] >= dep[b])
				a = f[a][j];

		if(a == b) return b;

		for(int j = 19; j >= 0; j --)
			if(f[a][j] != f[b][j])
			{
				a = f[a][j];
				b = f[b][j];
			}
		return f[a][0];
	};

	int q; cin >>q;
	vector<int> st(n + 1); int time = 0;
	vector<vector<int>> e(n + 1);
	vector<int> cnt(n + 1), near(n + 1), far(n + 1);
	while(q --)
	{
		time ++;

		int k; cin >>k;
		vector<int> v{1};
		v.reserve(2 * k + 1);
		for(int i = 0; i < k; i ++)
		{
			int x; cin >>x;
			v.push_back(x);
			st[x] = time;
		}

		sort(v.begin(), v.end(), [&](int i, int j)
		{
			return dfn[i] < dfn[j];
		});

		int siz = v.size();
		for(int i = 1; i < siz; i ++)
			v.push_back(lca(v[i - 1], v[i]));

		sort(v.begin(), v.end(), [&](int i, int j)
		{
			return dfn[i] < dfn[j]; 
		});
		v.erase(unique(v.begin(), v.end()), v.end());	

		for(auto x : v)
			e[x].clear();

		for(int i = 1; i < v.size(); i ++)
		{
			int fa = lca(v[i - 1], v[i]);
			e[fa].push_back(v[i]);
		}

		i64 sum = 0; int mn = INF, mx = -INF;
		[&](this auto &&self, int u) -> void
		{
			cnt[u] = (st[u] == time);
			
			if(st[u] == time) near[u] = far[u] = 0;
			else near[u] = INF, far[u] = -INF;

			for(auto v : e[u])
			{
				self(v);

				i64 len = dep[v] - dep[u];
				sum += len * cnt[v] * (k - cnt[v]);
				cnt[u] += cnt[v];

				int x = near[v] + dep[v] - dep[u];
				int y = far[v] + dep[v] - dep[u];
				if(near[u] != INF) mn = min(mn, x + near[u]);
				if(far[u] != -INF) mx = max(mx, y + far[u]);

				near[u] = min(near[u], x);
				far[u] = max(far[u], y);
			}
		}(1);
		cout <<sum <<" " <<mn <<" " <<mx <<endl;
	}
	return 0;
}
