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

	int n, m; cin >>n >>m;
	vector<int> w(n + 1), adj[n + 1];
	for(int i = 1; i <= n; i ++)
	{
		int p, c; cin >>p >>c;
		w[i] = c;

		adj[p].push_back(i);
		adj[i].push_back(p);
	}

	vector f(n + 1, vector<int>(m + 2));
	function <void(int, int)> dfs = [&](int u, int fa) -> void
	{
		f[u][1] = w[u];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);

			for(int j = m + 1; j >= 1; j --)
				for(int k = 1; k <= j - 1; k ++)
					f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
		}
	};

	dfs(0, -1);
	cout <<f[0][m + 1] <<endl;
	return 0;
}
