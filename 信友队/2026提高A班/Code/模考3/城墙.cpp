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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// freopen("wall.in", "r", stdin);
	// freopen("wall.out", "w", stdout);

	int n; cin >>n;
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>b[i];
	for(int i = 1; i <= n; i ++) cin >>c[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto bfs = [&](int s) -> vector<int>
	{
		vector<int> d(n + 1, INF);
		queue<int> q; q.emplace(s); d[s] = 0;
		while(q.size())
		{
			auto u = q.front(); q.pop();
			for(auto v : adj[u])
			{
				if(d[v] == INF)
				{
					d[v] = d[u] + 1;
					q.emplace(v);
				}
			}
		}
		return d;
	};

	i64 sumc = 0;
	for(int i = 1; i <= n; i ++) sumc += c[i];

	i64 ans = 0;
	for(int s = 1; s <= n; s ++)
	{
		auto dis = bfs(s);
		int D = *max_element(dis.begin() + 1, dis.end());

		if(D < 2) continue;

		vector<i64> sa(D + 1), sb(D + 1), sc(D + 1);

		for(int i = 1; i <= n; i ++)
		{
			sa[dis[i]] += a[i];
			sb[dis[i]] += b[i];
			sc[dis[i]] += c[i];
		}

		i64 pa = sa[0], pb = sb[0], pc = sc[0];

		i64 mx = pa - pb;
		for(int e = 1; e < D; e ++)
		{
			pa += sa[e];
			pb += sb[e];
			pc += sc[e];

			ans = max(ans, sumc + mx + pb - pc);
			mx = max(mx, pa - pb);
		}
	}
	cout <<ans <<endl;
	return 0;
}