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

	int n, m; cin >>n >>m;
	vector<vector<int>> a(m, vector<int>(n));
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++)
			cin >>a[i][j];

	vector<int> dis(1 << n, INF);
	dis[(1 << n) - 1] = 0;
	vector<vector<int>> adj(1 << n);
	for(int s = 0; s < (1 << n); s ++)
	{
		for(int i = 0; i < m; i ++)
		{
			int ns = 0;
			for(int j = 0; j < n; j ++)
			{
				int x = a[i][j], d = s >> j & 1;
				if(x == 1) d = 0;
				else if(x == -1) d = 1;

				ns += d * (1 << j);
			}
			adj[s].push_back(ns);
		}
	}
	queue<int> q;
	q.emplace((1 << n) - 1);
	while(q.size())
	{
		auto u = q.front(); q.pop();
		for(auto v : adj[u])
		{
			if(dis[v] == INF)
			{
				dis[v] = dis[u] + 1;
				q.emplace(v);
			}
		}
	}
	cout <<(dis[0] == INF ? -1 : dis[0]) <<endl;
	return 0;
}
