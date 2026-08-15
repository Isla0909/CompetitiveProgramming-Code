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

int p[N];
int siz[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if(a == b) return ;

	if(siz[a] < siz[b]) swap(a, b);

	p[b] = a;
	siz[a] += siz[b];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	vector<array<int, 3>> edges(m);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		edges[i] = {u, v, w};
	}
	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a[2] < b[2];
	});

	for(int i = 1; i <= n; i ++)
	{
		p[i] = i;
		siz[i] = 1;
	}

	vector<vector<pii>> adj(n + 1);
	int cnt = n;
	for(int i = 0; i < m && cnt != 1; i ++)
	{
		auto [u, v, w] = edges[i];
		if(find(u) == find(v)) continue;

		merge(u, v);
		cnt --;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<int> dep(n + 1);
	int len = __lg(n) + 1;
	vector f(n + 1, vector<int>(len)), mx(n + 1, vector<int>(len));
	auto dfs = [&](this auto &&self, int u, int fa, int w) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa, mx[u][0] = w;

		for(int j = 1; j < len; j ++)
		{
			f[u][j] = f[f[u][j - 1]][j - 1];
			mx[u][j] = max(mx[u][j - 1], mx[f[u][j - 1]][j - 1]);
		}

		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;
			self(v, u, w);
		}
	};
	dfs(1, 0, 0);

	auto get = [&](int a, int b) -> int
	{
		if(dep[a] < dep[b]) swap(a, b);

		int res = 0;
		for(int j = len - 1; j >= 0; j --)
			if(dep[f[a][j]] >= dep[b])
			{
				res = max(res, mx[a][j]);
				a = f[a][j];
			}

		if(a == b) return res;

		for(int j = len - 1; j >= 0; j --)
			if(f[a][j] != f[b][j])
			{
				res = max(res, mx[a][j]), a = f[a][j];
				res = max(res, mx[b][j]), b = f[b][j];
			}
		return max({res, mx[a][0], mx[b][0]});
	};
	
	while(q --)
	{
		int u, v, w; cin >>u >>v >>w;
		int mx = get(u, v);
		cout <<(w < mx ? "Yes" : "No") <<endl;
	}

	return 0;
}
