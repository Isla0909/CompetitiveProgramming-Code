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
		for(int i = 0; i < m; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
		}

		vector<int> vis(n + 1);
		vector<int> cycle, mul;
		auto dfs = [&](this auto &&self, int u) -> void
		{
			vis[u] = 1;
			for(auto v : adj[u])
			{
				if(!vis[v]) self(v);
				else if(vis[v] == 1)  cycle.push_back(v);
				else mul.push_back(v);
			}
			vis[u] = 2;
		};
		dfs(1);

		vector<bool> bad(n + 1), many(n + 1);
		auto paint = [&](this auto &&self, int u, vector<bool> &mark) -> void
		{
			if(mark[u]) return ;
			mark[u] = true;
			for(auto v : adj[u])
				self(v, mark);
		};

		for(auto u : cycle)
			paint(u, bad);
		for(auto u : mul)
			paint(u, many);

		for(int i = 1; i <= n; i ++)
		{
			int ans;
			if(!vis[i]) ans = 0;
			else if(bad[i]) ans = -1;
			else if(many[i]) ans = 2;
			else ans = 1;
			cout <<ans <<" \n"[i == n];
		}
	}
	return 0;
}
