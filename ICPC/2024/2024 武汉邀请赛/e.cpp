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

struct cxy
{
	int a, b, d;

	cxy() {}
	cxy(int a, int b, int d) : a(a), b(b), d(d) {}
};

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

	int root, t0; cin >>root >>t0;
	vector<int> dep(n + 1);
	vector<array<int, 20>> f(n + 1);
	[&](this auto &&self, int u, int fa) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa;

		for(int j = 1; j < 20; j ++)
			f[u][j] = f[f[u][j - 1]][j - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u);
		}
	}(root, 0);

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

	auto dis = [&](int a, int b) -> int
	{
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	};

	vector<int> D(2 * n + 1);
	cxy cur(root, root, 0);

	queue<int> q;
	q.emplace(root);

	while(q.size())
	{
		auto u = q.front(); q.pop();

		auto &[a, b, d] = cur;
		int d1 = dis(a, u), d2 = dis(b, u);
		if(d1 >= d2 && d1 > d) d = d1, b = u;
		else if(d2 > d) d = d2, a = u;

		D[dep[u] - 1] = d;
		for(auto v : adj[u])
		{
			if(v == f[u][0]) continue;
			q.emplace(v);
		}
	}

	for(int t = 1; t <= 2 * n; t ++)
		D[t] = max(D[t], D[t - 1]);

	vector<int> ans(n + 1);
	int t = t0;
	for(int k = n; k >= 1; k --)
	{
		while(1LL * k * (t - t0) < (D[t] + 1) / 2) t ++;
		ans[k] = t;
	}
	for(int k = 1; k <= n; k ++)
		cout <<ans[k] <<" \n"[k == n];
	return 0;
}
