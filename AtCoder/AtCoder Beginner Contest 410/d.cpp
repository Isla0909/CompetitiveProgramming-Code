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

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<pii> adj[n + 1];
	while(m --)
	{
		int a, b, c; cin >>a >>b >>c;
		adj[a].emplace_back(b, c);
	}
	int ans = INF; vector st(n + 1, vector<bool>(2049));
	queue<pii> q; q.push({1, 0});
	while(q.size())
	{
		auto [u, c] = q.front(); q.pop();
		for(auto [v, w] : adj[u])
		{
			if(!st[v][c ^ w])
			{
				st[v][c ^ w] = 1;
				q.push({v, c ^ w});
			}
		}
	}
	for(int i = 0; i <= 1024; i ++)
		if(st[n][i]) ans = min(ans, i);
	cout <<((ans == INF) ? -1 : ans) <<endl;
	return 0;
}