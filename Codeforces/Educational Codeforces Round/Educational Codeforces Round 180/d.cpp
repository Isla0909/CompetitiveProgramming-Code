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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int x = 1;
		while(x <= n and adj[x].size() != 2) x ++;
		if(x > n)
		{
			cout <<"NO" <<endl;
			continue;
		}
		cout <<"YES" <<endl;
		auto dfs = [&](this auto &&self, int u, int fa, int c) -> void
		{
			if(c) cout <<u <<" " <<fa <<endl;
			else cout <<fa <<" " <<u <<endl;

			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u, 1 - c);
			}
		};
		dfs(adj[x][0], x, 1);
		dfs(adj[x][1], x, 0);
	}
	return 0;
}