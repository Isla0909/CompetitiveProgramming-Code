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

struct SCC
{
	int n;
	vector<vector<int>> adj;
	vector<int> stk;
	vector<int> a;
	vector<int> dfn, low, bel, siz, sum;
	int cur, cnt;

	void initial(int n)
	{
		this->n = n;
		adj.assign(n + 1, {});
		dfn.assign(n + 1, -1);
		low.assign(n + 1, -1);
		bel.assign(n + 1, -1);
		siz.assign(n + 1, 0);
		a.assign(n + 1, 0);
		sum.assign(n + 1, 0);
		stk.clear();
		cur = cnt = 0;
	}


	SCC() {}
	SCC(int n)
	{
		initial(n);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}

	void tarjan(int u)
	{
		dfn[u] = low[u] = cur ++;
		stk.push_back(u);

		for(auto v : adj[u])
		{
			if(dfn[v] == -1)
			{
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}
			else if(bel[v] == -1) low[u] = min(low[u], dfn[v]);
		}

		if(dfn[u] == low[u])
		{
			int pre; cnt ++;
			do
			{
				pre = stk.back();
				bel[pre] = cnt;
				siz[cnt] ++;
				sum[cnt] += a[pre];
				stk.pop_back();
			}while(pre != u);
		}
	}
	auto work()
	{
		for(int i = 1; i <= n; i ++)
			if(dfn[i] == -1)
				tarjan(i);
		vector<vector<int>> dag(cnt + 1);
		for(int i = 1; i <= n; i ++)
		{
			for(auto j : adj[i])
			{
				int a = bel[i], b = bel[j];
				if(a != b) dag[a].push_back(b);
			}
		}
		return dag;
	}

	int get_cnt()
	{
		return cnt;
	}
	auto get_bel()
	{
		return bel;
	}
	auto get_siz()
	{
		return siz;
	}

};
//性质:缩点后的图拥有拓扑序,可以不需再另跑一遍topsort,缩点后的图是DAG

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	SCC scc(n);
	for(int i = 1; i <= n; i ++)
		cin >>scc.a[i];
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		scc.addEdge(u, v);
	}
	
	auto dag = scc.work();
	int cnt = scc.get_cnt();

	vector<int> f(cnt + 1); int ans = -INF;
	for(int i = 1; i <= cnt; i ++)
		f[i] = scc.sum[i];

	for(int u = cnt; u >= 1; u --)
	{
		ans = max(ans, f[u]);
		for(auto v : dag[u])
			f[v] = max(f[v], f[u] + scc.sum[v]);
	}
	cout <<ans <<endl;
	return 0;
}
