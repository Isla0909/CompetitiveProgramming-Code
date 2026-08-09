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

	int n, m; cin >>n >>m;
	vector<vector<int>> adj(n + 1);
	while(m --)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i ++) cin >>p[i];

	vector<int> deg(n + 1);
	for(int i = 1; i <= n; i ++)
		deg[i] = adj[i].size();

	vector<pii> ans;
	vector<int> stk, vis(n + 1, -1);
	for(int i = 1; i <= n; i ++)
	{
		int u = p[i];
		while(stk.size() && deg[stk.back()] == 0) stk.pop_back();

		for(auto v : adj[u])
		{
			vis[v] = u;
		}

		if(!stk.size()) stk.push_back(u);
		else
		{
			if(vis[stk.back()] != u) ans.emplace_back(stk.back(), u);
			stk.push_back(u);
		}

		for(auto v : adj[u])
			deg[v] --;
	}
	cout <<ans.size() <<endl;
	for(auto [u, v] : ans)
		cout <<u <<" " <<v <<endl;
	return 0;
}