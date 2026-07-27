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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

struct cxy
{
	int d, u, lev;
	cxy() {}
	cxy(int d, int u, int lev) : d(d), u(u), lev(lev) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1), ans(n + 1, -1);
	vector<pii> edges;
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
		deg[u] ++, deg[v] ++;
	}

	for(int i = 1; i <= n; i ++)
	{
		if(adj[i].size() <= 1) continue;
		sort(adj[i].begin(), adj[i].end(), [&](int u, int v)
		{
			return deg[u] > deg[v];
		});
	}

	queue<cxy> q;
	vector<int> f(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		if(!adj[i].size()) continue;
		int v = adj[i][0];
		if(deg[i] < deg[v])
		{
			ans[i] = 1;
			q.emplace(1, i, deg[v]);
			f[i] = deg[v];
		}
	}
	while(q.size())
	{
		auto [d, u, lev] = q.front(); q.pop();
		for(auto v : adj[u])
		{
			if(ans[v] != -1)
			{
				if(f[v] < lev)
				{
					f[v] = lev;
					q.emplace(d + 1, v, lev);
				}
			}
			else
			{
				if(deg[v] < lev)
				{
					ans[v] = d + 1;
					q.emplace(ans[v], v, lev);
				}
			}
		}
	}
	tell(1, ans);
	return 0;
}
