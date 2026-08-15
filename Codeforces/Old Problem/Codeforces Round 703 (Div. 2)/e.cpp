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
#include <array>
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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int d[N][51];
bool st[N][51];

struct cxy
{
	int u, last, dist;
	cxy(int u, int last, int dist) : u(u), last(last), dist(dist) {}

	bool operator>(const cxy &T) const
	{
		return dist > T.dist;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<pii>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	memset(d, 0x3f, sizeof d);

	d[1][0] = 0;
	priority_queue<cxy, vector<cxy>, greater<>> q;
	q.emplace(1, 0, 0);
	while(q.size())
	{
		auto [u, last, dist] = q.top(); q.pop();

		if(st[u][last]) continue;
		st[u][last] = true;

		for(auto [v, w] : adj[u])
		{
			if(last == 0)
			{
				if(d[v][w] > d[u][last])
				{
					d[v][w] = d[u][last];
					q.emplace(v, w, dist);
				}
			}
			else
			{
				if(d[v][0] > d[u][last] + (last + w) * (last + w))
				{
					d[v][0] = d[u][last] + (last + w) * (last + w);
					q.emplace(v, 0, d[v][0]);
				}
			}
		}
	}
	for(int u = 1; u <= n; u ++)
		cout <<(d[u][0] == INF ? -1 : d[u][0]) <<" \n"[u == n];
	return 0;
}
