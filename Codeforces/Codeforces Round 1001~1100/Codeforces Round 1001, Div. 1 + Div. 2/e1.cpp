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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 4e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct BinaryIndexedTree
{
	#define lowbit(x) (x & -x)

	int n; vector<int> tr;

	BinaryIndexedTree(int n) : n(n), tr(n + 1, 0) {};

	void update(int x, int c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	int query(int x)
	{
		int res = 0;
		for(int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
};


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		BinaryIndexedTree tr(n);
		vector<int> w(n + 1), dfn(n + 1), adj[n + 1];
		vector<int> d(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>w[i];
			tr.update(w[i], 1);
			dfn[i] = i;
		}
		for(int i = 1; i <= n; i ++)
			d[i] = tr.query(n) - tr.query(w[i]);//比当前节点的权值要大的点的个数

		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		function <void (int, int)> dfs;
		dfs = [&](int u, int fa)
		{
			int now = tr.query(n) - tr.query(w[u]);
			tr.update(w[u], 1);
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				dfs(v, u);
			}
			if(d[u] == tr.query(n) - tr.query(w[u]) - now) d[u] = 0;
			else d[u] = 1;
		};
		dfs(1, -1);

		auto cmp = [&](int a, int b) -> bool
		{
			return w[a] > w[b];
		};

		sort(dfn.begin() + 1, dfn.end(), cmp);
		int ans = 0;
		for(int i = 1; i <= n; i ++)
			if(d[dfn[i]])
			{
				ans = dfn[i];
				break;
			}
		cout <<ans <<endl;
	}
	return 0;
}