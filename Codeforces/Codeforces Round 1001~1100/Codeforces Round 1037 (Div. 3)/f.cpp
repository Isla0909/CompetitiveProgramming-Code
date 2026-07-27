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
#define int long long
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
		int n, m; cin >>n >>m;
		int len = sqrt(n);

		vector<int> col(n + 1), d(n + 1);
		for(int i = 1; i <= n; i ++) cin >>col[i];

		vector<pii> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int a, b, c; cin >>a >>b >>c;
			adj[a].emplace_back(b, c);
			adj[b].emplace_back(a, c);

			d[a] ++, d[b] ++;
		}

		vector<bool> f(n + 1);
		for(int i = 1; i <= n; i ++)
			f[i] = (d[i] >= len);

		int ans = 0; vector<map<int, int>> mp(n + 1);
		for(int u = 1; u <= n; u ++)
		{
			for(auto [v, w] : adj[u])
			{
				if(u < v && col[u] != col[v]) ans += w;

				if(f[u] && !f[v]) mp[u][col[v]] += w;
			}
		}

		vector<pii> heavy[n + 1];
		for(int u = 1; u <= n; u ++)
		{
			if(!f[u]) continue;
			for(auto [v, w] : adj[u])
			{
				if(f[v]) heavy[u].emplace_back(v, w);
			}
		}

		while(m --)
		{
			int u, x; cin >>u >>x;
			if(col[u] == x)
			{
				cout <<ans <<endl;
				continue;
			}
			int c = col[u];
			if(!f[u])
			{
				for(auto [v, w] : adj[u])
				{
					if(col[v] == c) ans += w;
					if(col[v] == x) ans -= w;

					if(f[v])
					{
						mp[v][c] -= w;
						mp[v][x] += w;
					}
				}
			}
			else
			{
				ans += mp[u][c];
				ans -= mp[u][x];

				for(auto [v, w] : heavy[u])
				{
					if(col[v] == c) ans += w;
					if(col[v] == x) ans -= w;
				}
			}
			col[u] = x;
			cout <<ans <<endl;
		}
	}
	return 0;
}