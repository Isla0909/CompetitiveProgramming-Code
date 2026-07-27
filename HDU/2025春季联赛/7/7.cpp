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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
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

struct cxy
{
	int to;
	int w1, w2;

	cxy(int v, int w1, int w2) : to(v), w1(w1), w2(w2) {}
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<cxy> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int a, b, c, d; cin >>a >>b >>c >>d;
			adj[a].emplace_back(b, c, d);
			adj[b].emplace_back(a, d, c);
		}
		int s, e; cin >>s >>e;
		vector<ll> d(n + 1);
		function <void(int, int)> dfs = [&](int u, int fa) -> void
		{
			for(auto [v, w1, w2] : adj[u])
			{
				if(v == fa) continue;

				dfs(v, u);
				d[u] += max(0LL, d[v] + w1 + w2);
			}
		};
		dfs(s, -1);
		function <pair<bool, ll>(int, int)> solve = [&](int u, int fa) -> pair<bool, ll>
		{
			if(u == e) return {true, d[e]};

			ll res = 0; bool f = 0;
			for(auto [v, w1, w2] : adj[u])
			{
				if(v == fa) continue;
				auto [flag, val] = solve(v, u);

				if(flag) f = 1, res += w1 + val;
				else res += max(0LL, d[v] + w1 + w2); 
			}
			return {f, res};
		};
		cout <<solve(s, -1).se <<endl;
	}
	return 0;
}