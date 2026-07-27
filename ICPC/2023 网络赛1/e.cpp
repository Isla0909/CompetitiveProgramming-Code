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

	int T; cin >>T;
	while(T --)
	{
		int n, m, d; cin >>n >>m >>d;
		vector<vector<int>> adj(n + 1);
		for(int i = 0; i < m; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int k; cin >>k;
		vector<int> s(k + 1);
		for(int i = 1; i <= k; i ++) cin >>s[i];

		queue<array<int, 2>> q;
		vector<array<int, 2>> t(n + 1, {INF, INF});
		for(int i = 1; i <= k; i ++)
		{
			t[s[i]][0] = 0;
			q.push({s[i], 0});
		}

		while(q.size())
		{
			auto [u, c] = q.front(); q.pop();
			if(t[u][c] == d) continue;

			for(auto v : adj[u])
			{
				if(t[v][c ^ 1] == INF)
				{
					t[v][c ^ 1] = t[u][c] +1 ;
					q.push({v, c ^ 1});
				}
			}
 		}

 		assert(q.empty());

 		vector<array<int, 2>> t_(n + 1, {INF, INF});
 		vector<array<int, 2>> pre(n + 1);
 		q.push({1, 0}); t_[1][0] = 0;
 		while(q.size())
 		{
 			auto [u, c] = q.front(); q.pop();
 			for(auto v : adj[u])
 			{
 				if(t_[v][c ^ 1] == INF && (t[v][c ^ 1] == INF || t_[u][c] + 1 < t[v][c ^ 1]))
 				{
 					t_[v][c ^ 1] = t_[u][c] + 1;
 					pre[v][c ^ 1] = u;
 					q.push({v, c ^ 1});
 				}
 			}
 		}

 		if(t_[n][0] == INF && t_[n][1] == INF)
		{
			cout <<-1 <<endl;
			continue;
		}

		int x = 0;
		if(t_[n][1] < t_[n][0]) x = 1;

		vector<int> path;
		int y = n;
		while(1)
		{
			path.push_back(y);
			if(y == 1 && x == 0) break;

			y = pre[y][x];
			x ^= 1;
		}
		reverse(path.begin(), path.end());
		cout <<path.size() - 1 <<endl;
		tell(0, path);
	}
	return 0;
}
