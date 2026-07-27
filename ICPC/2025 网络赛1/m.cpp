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

constexpr int N = 5000 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	i64 d;
	int u;
	int k;

	cxy(i64 d, int u, int k) : d(d), u(u), k(k) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	while(m --)
	{
		int u, v; cin >>u >>v;
		adj[u].emplace_back(v, 0);
		adj[v].emplace_back(u, 0);
	}

	vector d(n + 1, vector<i64>(n + 1, inf));
	vector st(n + 1, vector<bool>(n + 1));
	queue<cxy> q;
	
	for(int i = 0; i <= n; i ++)
		d[1][i] = 0;

	for(int i = 0; i <= n; i ++)
	{
		if(i) q.emplace(0, 1, i - 1), st[1][i - 1] = 1;
		else q.emplace(0, 1, 0), st[1][0] = 1;
		for(int u = 2; u <= n; u ++)
			if(i)
			{
				q.emplace(d[u][i - 1], u, i - 1);
				st[u][i - 1] = 1;
				d[u][i] = d[u][i - 1];
			}
		while(q.size())
		{
			auto [dis, u, k] = q.front(); q.pop(); st[u][k] = 0;

			for(auto [v, w] : adj[u])
			{
				if(w)//非传送门
				{
					if(d[v][k] > dis + w)
					{
						d[v][k] = dis + w;
						if(!st[v][k]) q.emplace(d[v][k], v, k);
					}
				}
				else
				{
					if(k + 1 <= i && d[v][k + 1] > dis)
					{
						d[v][k + 1] = dis;
						if(!st[v][k + 1]) q.emplace(d[v][k + 1], v, k + 1);
					}
				}
			}
		}
	}
	vector<i64> ans(n + 1);
	for(int i = 0; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			ans[i] += d[j][i];
	for(int i = 0; i <= n; i ++)
		cout <<ans[i] <<"\n";
	return 0;
}