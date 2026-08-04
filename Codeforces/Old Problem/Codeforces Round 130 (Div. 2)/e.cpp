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
	vector<int> root;
	for(int i = 1; i <= n; i ++)
	{
		int fa; cin >>fa;
		if(!fa) root.push_back(i);
		else
		{
			adj[i].push_back(fa);
			adj[fa].push_back(i);
		}
	}

	vector<int> dep(n + 1), in(n + 1), siz(n + 1);
	int len = __lg(n) + 1, cur = 0;
	vector f(n + 1, vector<int>(len));
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		in[u] = ++ cur;
		dep[u] = dep[fa] + 1;
		f[u][0] = fa, siz[u] = 1;

		for(int j = 1; j < len; j ++)
			f[u][j] = f[f[u][j - 1]][j - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
			siz[u] += siz[v];
		}
	};
	
	for(auto x : root)
		dfs(x, 0);

	auto get = [&](int x, int k) -> int
	{
		if(dep[x] <= k) return -1;

		for(int j = len - 1; j >= 0; j --)
			if(k >> j & 1) x = f[x][j];
		return x;
	};

	vector<vector<int>> vec(n + 1);
	for(int u = 1; u <= n; u ++)
		vec[dep[u]].push_back(in[u]);
	
	for(int i = 1; i <= n; i ++)
	{
		if(vec[i].size() <= 1) continue;
		sort(vec[i].begin(), vec[i].end());
	}

	auto calc = [&](int x, int l, int r)
	{
		int tot = upper_bound(vec[x].begin(), vec[x].end(), r) - vec[x].begin();
		return tot - (lower_bound(vec[x].begin(), vec[x].end(), l) - vec[x].begin());
	};

	int m; cin >>m;
	for(int i = 1; i <= m; i ++)
	{
		int x, p; cin >>x >>p;

		int u = get(x, p);
		if(u == -1) cout <<0 <<" \n"[i == m];
		else
		{
			int l = in[u], r = in[u] + siz[u] - 1;
			cout <<calc(dep[x], l, r) - 1 <<" \n"[i == m];
		}
	}
	return 0;
}
