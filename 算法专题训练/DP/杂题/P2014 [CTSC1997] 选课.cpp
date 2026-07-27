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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<int> adj[n + 1], w(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int a, b; cin >>a >>b;
		w[i] = b;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	vector<int> siz(n + 1);
	int v[N], len = 0;
	function <void(int, int)> dfs;
	dfs = [&](int u, int fa) -> void
	{
		siz[u] = 1; v[++ len] = u;
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);
			siz[u] += siz[v];
		}
	};
	dfs(0, -1);
	vector f(n + 3, vector<int>(m + 2));//f[i][j]表示从 DFS 序的第 i 个节点开始，选择 j 门课程的最大学分
	for(int i = len; i >= 1; i --)
		for(int j = 1; j <= m + 1; j ++)
			f[i][j] = max(f[ i + siz[v[i]] ][j], f[i + 1][j - 1] + w[v[i]]);
	//若i不选,则i的子树都不能选,于是跳过i及i的子树
	//若i要选,则进入i的子树中接着选; 
	cout <<f[1][m + 1] <<endl;
	return 0;
}