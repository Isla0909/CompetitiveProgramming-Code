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
		int s, e; cin >>s >>e;
		vector<vector<int>> adj(n + 1);
		vector<int> leaves;
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for(int i = 1; i <= n; i ++)
			if(adj[i].size() == 1) leaves.push_back(i);

		int len = __lg(2 * n - 1);
		vector f(n + 1, vector<int>(len));
		vector<int> dep(n + 1);

		
		function<void(int, int)> dfs = [&](int u, int fa) -> void
		{
			f[u][0] = fa;
			dep[u] = dep[fa] + 1;

			for(int i = 1; i < len; i ++)
				f[u][i] = f[f[u][i - 1]][i - 1];

			for(auto v : adj[u])
			{
				if(v == fa) continue;

				dfs(v, u);
			}
		};

		dfs(1, 0);

		auto lca = [&](int a, int b) -> int
		{
			if(dep[a] < dep[b]) swap(a, b);

			for(int k = len - 1; k >= 0; k --)
				if(dep[f[a][k]] >= dep[b])
					a = f[a][k];

			if(a == b) return b;

			for(int k = len - 1; k >= 0; k --)
				if(f[a][k] != f[b][k])
				{
					a = f[a][k];
					b = f[b][k];
				}
			return f[a][0];
		};

		auto dist = [&](int a, int b) -> int
		{
			return dep[a] + dep[b] - 2 * dep[lca(a, b)];
		};

		bool h = 0;
		int c = dist(s, e);
		//cout <<c <<endl;
		for(auto u : leaves)
		{
			if(u != e && dist(u, s) <= (dist(u, e) + 1) / 2 && dist(u, s) <= dist(u, e) && dist(u, s) <= c)
			{
				h = 1;
				break;
			}
		}
		cout <<(h ? "red" : "purple") <<endl;
	}
	return 0;
}
