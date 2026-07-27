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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n; vector<int> a(3);
	map<pii, vector<int>> mp;
	for(int i = 1; i <= n - 2; i ++)
	{
		for(auto &x : a) cin >>x;
		sort(a.begin(), a.end());

		mp[{a[0], a[1]}].push_back(i);
		mp[{a[0], a[2]}].push_back(i);
		mp[{a[1], a[2]}].push_back(i);
	}

	vector<int> adj[n];
	for(auto [_, v] : mp)
	{
		for(int i = 0; i < v.size(); i ++)
			for(int j = i + 1; j < v.size(); j ++)
			{
				adj[v[i]].push_back(v[j]);
				adj[v[j]].push_back(v[i]);

				//cout <<v[i] <<" " <<v[j] <<endl;
			}
	}
	int res = 0; vector<int> d1(n), d2(n);
	function <int(int, int)> dfs;
	dfs = [&](int u, int fa) -> int
	{
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			int d = dfs(v, u) + 1;
			if(d > d1[u]) d2[u] = d1[u], d1[u] = d;
			else if(d > d2[u]) d2[u] = d;
		}
		res = max(res, d1[u] + d2[u]);
		return d1[u];
	};
	dfs(1, -1);
	cout <<res + 1 <<endl;
	return 0;
}