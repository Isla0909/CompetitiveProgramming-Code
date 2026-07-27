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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
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
		vector<int> l(n + 1), r(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >>l[i] >>r[i];
		vector<int> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> siz(n + 1), f(n + 1); u128 ans = 0;
		function <void (int, int)> dfs;
		dfs = [&](int u, int fa)
		{
			siz[u] = 1, f[u] = l[u];
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				dfs(v, u);
				siz[u] += siz[v];
				f[u] = min(r[u], max(f[u], f[v]));
			}
			ans += f[u];
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				if(f[u] > f[v]) ans += 1LL * (f[u] - f[v]) * siz[v];
				else ans += 1LL * (f[v] - f[u]) * (n - siz[v]);
			}
		};
		dfs(1, -1);
		ans /= n;
		cout <<(ll)ans <<endl;
	}
	return 0;
}