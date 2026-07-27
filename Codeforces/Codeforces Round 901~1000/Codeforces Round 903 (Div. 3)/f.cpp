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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<bool> st(n + 1);
		for(int i = 0; i < k; i ++)
		{
			int x; cin >>x;
			st[x] = 1;
		}

		vector<vector<int>> adj(n + 1);
		vector<int> deg(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);

			deg[u] ++, deg[v] ++;
		}

		vector<bool> on(n + 1, true);
		queue<int> q;
		for(int i = 1; i <= n; i ++)
		{
			if(deg[i] == 1 && !st[i])
				q.push(i);
		}
		while(!q.empty())
		{
			auto u = q.front(); q.pop();
			on[u] = false;
			for(auto v : adj[u])
			{
				deg[v] --;
				if(deg[v] == 1 && !st[v])
					q.push(v);
			}
		}
		
		int r = 1, cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(st[i] && deg[i] == 1) r = i;
			if(!st[i] && on[i]) cnt ++;
		}
		//cout <<r <<endl;
		vector<int> dep(n + 1); int c = r;
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			for(auto v : adj[u])
			{
				if(v == fa || !on[v]) continue;
				dep[v] = dep[u] + 1;
				if(dep[v] > dep[c]) c = v;
				self(v, u);
			}
		};
		int r1, r2;
		dfs(r, -1); r1 = c;
		// for(int i = 1; i <= n; i ++)
		// {
		// 	if(on[i]) cout <<i <<" " <<dep[i] <<endl;
		// }
		dep[c] = 0; dfs(c, -1); r2 = c;
		//cout <<r1 <<" " <<r2 <<endl;
		cout <<(dep[r2] + 1) / 2 <<endl; 
	}
	return 0;
}