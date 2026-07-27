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

	int n, t; cin >>n >>t;
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i <= t; i ++)
	{
		int m; cin >>m;
		while(m --)
		{
			int u, v; cin >>u >>v;
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}
	}
	int k; cin >>k;
	vector<int> a(k + 1);
	vector<vector<int>> pos(t + 1);
	for(int i = 1; i <= k; i ++)
	{
		cin >>a[i];
		pos[a[i]].push_back(i);
	}

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, 1);
	vector<int> dis(n + 1, -1);
	while(!q.empty())
	{
		auto [d, u] = q.top(); q.pop();

		if(dis[u] != -1) continue;
		dis[u] = d;

		for(auto [v, i] : adj[u])
		{
			auto it = upper_bound(pos[i].begin(), pos[i].end(), d);
			if(it != pos[i].end())
				q.emplace(*it, v);
		}
	}
	cout <<dis[n] <<endl;
	return 0;
}