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
	vector<int> deg(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u] ++, deg[v] ++;
	}

	if(n == 2)
	{
		cout <<"2 2" <<endl;
		cout <<"1 1" <<endl;
		return 0;
	}

	vector<array<int, 2>> f(n + 1), g(n + 1);
	[&](this auto &&self, int u, int fa) -> void
	{
		f[u][1] = 1, f[u][0] = 0;
		g[u][1] = deg[u], g[u][0] = 1;

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);

			f[u][1] += f[v][0], g[u][1] += g[v][0];
			f[u][0] += max(f[v][1], f[v][0]);

			if(f[v][0] == f[v][1]) g[u][0] += min(g[v][0], g[v][1]);
			else g[u][0] += (f[v][1] > f[v][0]) ? g[v][1] : g[v][0];
		}
	}(1, 0);

	vector<bool> st(n + 1);
	[&](this auto &&self, int u, int fa, int col) -> void
	{
		if(col) st[u] = 0;
		else
		{	
			if(f[u][0] > f[u][1] || f[u][0] == f[u][1] && g[u][0] < g[u][1]) st[u] = 0;
			else st[u] = 1;
		}

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u, st[u]);
		}
	}(1, 0, 0);

	if(f[1][1] == f[1][0]) cout <<f[1][1] <<" " <<min(g[1][0], g[1][1]) <<endl;
	else if(f[1][1] > f[1][0]) cout <<f[1][1] <<" " <<g[1][1] <<endl;
	else cout <<f[1][0] <<" " <<g[1][0] <<endl;

	for(int u = 1; u <= n; u ++)
		cout <<(st[u] ? deg[u] : 1) <<" \n"[u == n];
	return 0;
}
