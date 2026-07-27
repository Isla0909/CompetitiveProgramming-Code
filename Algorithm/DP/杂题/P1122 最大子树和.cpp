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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n + 1), p(n + 1, -1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	vector<int> adj[n + 1];
	for(int i = 1; i < n; i ++)
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> f(n + 1, 0);
	function <void(int, int)> dfs;
	dfs = [&](int u, int fa) -> void
	{
		f[u] = a[u];
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);
			if(f[v] > 0) f[u] += f[v];
		}
	};
	dfs(1, -1);
	cout <<*max_element(f.begin() + 1, f.end()) <<endl;
	return 0;
}