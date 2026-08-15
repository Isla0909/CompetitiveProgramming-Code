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

struct Fenwick
{
	#define lowbit(x) x & -x

	int n;
	vector<i64> tr;
	Fenwick() {}
	Fenwick(int n)
	{
		initial(n);
	}

	void initial(int n)
	{
		this -> n = n;
		tr.assign(n + 1, 0LL);
	}

	void add(int x, i64 c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	i64 query(int x)
	{
		i64 res = 0;
		for(int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	void rangeAdd(int l, int r, i64 c)
	{
		add(l, c);
		if(r + 1 <= n) add(r + 1, -c);
	}
};

struct edge
{
	int u, v, w;
	edge() {}
	edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<vector<pii>> adj(n + 1);
	vector<edge> edges(n);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges[i] = {u, v, w};
	}

	vector<int> in(n + 1), siz(n + 1), dep(n + 1); int cur = 0;
	int len = __lg(n) + 1;
	vector f(n + 1, vector<int>(len));
	vector<i64> dist(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		in[u] = ++ cur;
		siz[u] = 1, dep[u] = dep[fa] + 1;
		f[u][0] = fa;

		for(int j = 1; j < len; j ++)
			f[u][j] = f[f[u][j - 1]][j - 1];

		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;
			dist[v] = dist[u] + w;
			self(v, u);
			siz[u] += siz[v];
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

	Fenwick bit(n);

	int q; cin >>q;
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int id, nw; cin >>id >>nw;
			auto [u, v, w] = edges[id];
			if(dep[v] < dep[u]) swap(v, u);

			int delta = nw - w;
			edges[id].w = nw;

			int l = in[v], r = in[v] + siz[v] - 1;
			bit.rangeAdd(l, r, delta);
		}
		else
		{
			int u, v; cin >>u >>v;
			int p = lca(u, v);
			cout <<dist[u] + bit.query(in[u]) + dist[v] + bit.query(in[v]) - 2 * (dist[p] + bit.query(in[p])) <<endl;
		}
	}
	return 0;
}
