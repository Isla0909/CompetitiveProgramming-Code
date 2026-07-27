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
		int n, m; cin >>n >>m;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		vector<int> dep(n + 1);
		vector<vector<int>> vec(n + 1);
		int s = 0;
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			dep[u] = dep[fa] + 1;
			vec[dep[u]].push_back(u);
			s = max(s, dep[u]);
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
			}
		};
		dfs(1, 0);

		vector<int> to(n + 1);
		for(int i = 1; i <= n; i ++)
			to[i] = s - dep[i];

		vector<int> val(n + 1);
		for(int i = 1; i <= m; i ++)
		{
			int pos, t; cin >>pos >>t;
			if(to[pos] <= t) val[pos] ++;
		}

		vector<int> up(n + 1);
		auto dfs1 = [&](this auto &&self, int u, int fa) -> void
		{
			up[u] = up[fa] + val[u];
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
			} 
		};
		dfs1(1, 0);

		vector<int> M(n + 1, 0);
		for(int i = 1; i <= n; i ++)
		{
			for(auto u : vec[i])
				M[i] = max(M[i], up[u]);
		}

		int ans = 0;
		vector<int> down(n + 1);
		auto dfs2 = [&](this auto &&self, int u, int fa) -> void
		{
			down[u] = val[u];
			int s = 0;
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);

				s = max(s, down[v]);
			}
			down[u] += s;
			ans = max(ans, down[u] + M[dep[u] - 1]);
		};
		dfs2(1, 0);
		cout <<ans <<endl;
	}
	return 0;
}
