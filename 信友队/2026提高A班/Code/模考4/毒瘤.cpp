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

struct CutPoint
{
	int n, idx;
	vector<vector<pii>> adj;
	vector<int> dfn, low;
	vector<int> is_cut;
	int cur;

	void initial(int n)
	{
		this->n = n;
		idx = 0;
		cur = 0;

		adj.assign(n + 1, {});
		dfn.assign(n + 1, -1);
		low.assign(n + 1, -1);
		is_cut.assign(n + 1, 0);
	}

	CutPoint() {}

	CutPoint(int n)
	{
		initial(n);
	}

	void addEdge(int u, int v)
	{
		// 无向图，一条边加两次
		// 但这两个方向共用同一个边编号 idx
		adj[u].push_back({v, idx});
		adj[v].push_back({u, idx});
		idx++;
	}

	void tarjan(int u, int from, int root)
	{
		dfn[u] = low[u] = cur++;
		int child = 0;

		for(auto [v, id] : adj[u])
		{
			// from 是父边编号，不是父节点
			// 不要写 v == fa，重边会错
			if(id == from) continue;

			if(dfn[v] == -1)
			{
				child++;
				tarjan(v, id, root);

				low[u] = min(low[u], low[v]);

				// 非根节点割点判断
				// low[v] >= dfn[u] 表示 v 子树回不到 u 的祖先
				if(u != root && low[v] >= dfn[u])
					is_cut[u] = 1;
			}
			else
			{
				// 返祖边
				low[u] = min(low[u], dfn[v]);
			}
		}

		// 根节点特殊判断
		// 根节点有两个及以上 DFS 子树才是割点
		if(u == root && child >= 2)
			is_cut[u] = 1;
	}

	auto work()
	{
		for(int i = 1; i <= n; i++)
			if(dfn[i] == -1)
				tarjan(i, -1, i);

		return is_cut;
	}

	auto get_cut()
	{
		return is_cut;
	}

	auto get_dfn()
	{
		return dfn;
	}

	auto get_low()
	{
		return low;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("cancer.in", "r", stdin);
	freopen("cancer.out", "w", stdout);

	int n, m; cin >>n >>m;
	CutPoint cut(n);
	vector<int> deg(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		cut.addEdge(u, v);
		deg[u] ++, deg[v] ++;
	}

	cut.work();

	vector<int> ans, st = cut.get_cut();
	for(int i = 1; i <= n; i ++)
	{
		if(m - deg[i] != (n - 1) - 1) continue;

		if(deg[i] == 1) ans.push_back(i);
		else if(!st[i]) ans.push_back(i);
	}

	cout <<ans.size() <<endl;
	tell(0, ans);
	return 0;
}
