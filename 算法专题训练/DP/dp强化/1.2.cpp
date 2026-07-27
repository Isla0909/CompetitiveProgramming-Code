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
#define ff first
#define se second
#define endl '\n'
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	vector <vector<int>> adj(n + 1);
	vector <int> d(n + 1, 0);
	for(int i = 1; i < n; i ++)	
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		d[a] ++, d[b] ++;
	}
	vector <bool> st(n + 1, 0);
	int x = 1; 
	for(int i = 0; i < k; i ++)
	{
		cin >>x;
		st[x] = 1;
	}
	
	auto dfs = [&](auto &&self, int u, int fa) -> bool
	{
		for(auto x : adj[u])
		{
			if(x == fa) continue;
			
			st[x] = self(self, x, u);
			if(st[x]) st[u] = 1;
		}
		if(st[u]) return true;
		return false;
	};

	dfs(dfs, x, -1);

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(st[i]) ans ++;
	cout <<ans <<endl;
	return 0;
}