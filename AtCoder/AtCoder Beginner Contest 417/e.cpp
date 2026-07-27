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
typedef pair<int, string> pis;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, s, e; cin >>n >>m >>s >>e;
		vector<int> adj[n + 1];
		while(m --)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> st(n + 1);
		for(int i = 1; i <= n; i ++)
			sort(adj[i].begin(), adj[i].end());

		vector<int> path;
		function <bool(int, int)> dfs = [&](int u, int fa) -> bool
		{
			st[u] = 1;
			if(u == e)
			{
				for(auto x : path)
					cout <<x <<" ";
				cout <<endl;
				return true;
			}
			if(st[u] == -1) return false;
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				if(!st[v])
				{
					path.push_back(v);
					if(dfs(v, u)) return true;
					path.pop_back();
				}
			}
			st[u] = -1;
			return false;
		};
		path.push_back(s);
		dfs(s, -1);
	}
	return 0;
}