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



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, H; cin >>n >>m >>H;
	vector<int> h(n + 1);
	for(int i = 1; i <= n; i ++) cin >>h[i];

	vector<vector<pii>> adj(n + 1);
	while(m --)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector d(n + 1, vector<i64>(H + 1, inf));
	vector st(n + 1, vector<bool>(H + 1));
	
	queue<pii> q;
	for(int i = 0; i <= H; i ++)
	{
		d[1][i] = 0;
		q.emplace(1, i); st[1][i] = 1;
	}

	while(q.size())
	{
		auto [u, k] = q.front(); q.pop(); st[u][k] = 0;

		for(auto [v, w] : adj[u])
		{
			if(h[u] > h[v])
			{
				if(d[v][0] > d[u][k] + w)
				{
					d[v][0] = d[u][k] + w;
					if(!st[v][0])
					{
						q.emplace(v, 0);
						st[v][0] = 1;
					}
				}
			}
			else
			{
				int delta = h[v] - h[u];
				if(k + delta <= H && d[v][k + delta] > d[u][k] + w)
				{
					d[v][k + delta] = d[u][k] + w;
					if(!st[v][k + delta])
					{
						q.emplace(v, k + delta);
						st[v][k + delta] = 1;
					}
				}
			}
		}
	}
	vector<i64> ans(n + 1, inf);
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= H; j ++)
			ans[i] = min(ans[i], d[i][j]);
	for(int i = 2; i <= n; i ++)
		cout <<(ans[i] == inf ? -1 : ans[i]) <<" \n"[i == n];
	return 0;
}
