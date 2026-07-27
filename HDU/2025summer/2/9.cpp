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

struct HLD
{
	int n;
	vector<int> siz, dep, top, fa, in, out, seq;
	vector<vector<int>> adj;
	int cur;

	void initial(int n)
	{
		this->n = n;
		siz.resize(n + 1);
		dep.resize(n + 1);
		top.resize(n + 1);
		fa.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
		seq.resize(n + 1);
		adj.assign(n + 1, {});
		cur = 1;
	}

	HLD() {}
	HLD(int n)
	{
		initial(n);
	}

	void add(int u, int v)
	{
		adj[u].push_back(v);
	}

	void dfs1(int u)//siz, dep, fa, son
	{
		if(fa[u] != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa[u]));

		siz[u] = 1;
		for(auto &v : adj[u])
		{
			fa[v] = u;
			dep[v] = dep[u] + 1;

			dfs1(v);
			siz[u] += siz[v];

			if(siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
		}
	}

	void dfs2(int u)
	{
		in[u] = cur ++;
		seq[in[u]] = u;

		for(auto v : adj[u])
		{
			top[v] = (v == adj[u][0]) ? top[u] : v;
			dfs2(v);
		}
		out[u] = cur;
	}

	void work(int root = 1)
	{
		top[root] = root;
		fa[root] = -1;
		dep[root] = 0;
		dfs1(root), dfs2(root);
	}

	int lca(int u, int v)
	{
		while(top[u] != top[v])
		{
			if(dep[top[u]] > dep[top[v]]) u = fa[top[u]];
			else v = fa[top[v]];
		}
		return dep[u] < dep[v] ? u : v;
	}

	int dis(int u, int v)
	{
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}

	bool isAncester(int u, int v)
	{
		return in[u] <= in[v] && in[v] < out[u];
	}

	int jump(int u, int k)
	{
		assert(dep[u] >= k);

		int d = dep[u] - k;
		while(dep[top[u]] > d) u = fa[top[u]];

		//dep[u] - dep[v] = in[u] - in[v]
		//in[v] = in[u] + dep[v] - dep[u];
		return seq[in[u] + d - dep[u]];
	}
};

struct SegmentTree
{
	struct node
	{
		int l, r;
		i64 sum, val1, val2, lazy;
	};

	vector<int> w;
	vector<node> tr;

	void initial(int n)
	{
		w.resize(n + 1);
		tr.resize(4 * n + 1);

		auto build = [this](auto &&self, int u, int l, int r) -> void
		{
			if(l == r)
			{
				tr[u] = {l, r, w[l], w[l], w[l], 0};
				return ;
			}
			tr[u] = {l, r};
			int mid = l + r >>1;
			self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
			pushup(u); 
		};
		build(build, 1, 1, n);
	}

	void pushup(int u)
	{
		auto pushup = [&](node &u, node &l, node &r)
		{
			u.sum = l.sum + r.sum;
			u.val1 = max(l.val1, r.val1);
			u.val2 = min(l.val2, r.val2);
		};
		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	SegmentTree() {}
	SegmentTree(int n)
	{
		initial(n);
	}
	SegmentTree(vector<int> &a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		initial(n);
	}

	void apply_add(node &u, i64 lazy)
	{
		u.sum += (u.r - u.l + 1) * lazy;
		u.val1 += lazy, u.val2 += lazy;
		u.lazy += lazy;
	}

	void pushdown(int u)
	{
		if(tr[u].lazy == 0) return ;
		apply_add(tr[u << 1], tr[u].lazy);
		apply_add(tr[u << 1 | 1], tr[u].lazy);
		tr[u].lazy = 0;
	}

	void rangeAdd(int u, int l, int r, int x)
	{
		if(tr[u].l >= l && tr[u].r <= r)
		{
			apply_add(tr[u], x);
			return ;
		}
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) rangeAdd(u << 1, l, r, x);
		if(r >= mid + 1) rangeAdd(u << 1 | 1, l, r, x);
		pushup(u);
	}

	i64 rangeSum(int u, int l, int r)
	{
		if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		i64 res = 0;
		if(l <= mid) res += rangeSum(u << 1, l, r);
		if(r >= mid + 1) res += rangeSum(u << 1 | 1, l, r);
		return res;
	}

	i64 max_query(int u, int l, int r)
	{
		if(tr[u].l >= l && tr[u].r <= r) return tr[u].val1;

		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;

		i64 res = -inf;
		if(l <= mid) res = max(res, max_query(u << 1, l, r));
		if(r >= mid + 1) res = max(res, max_query(u << 1 | 1, l, r));
		return res;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> a(n + 1), w(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		HLD hld(n);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			hld.add(u, v), hld.add(v, u);
		}
		hld.work();

		for(int i = 1; i <= n; i ++)
			w[i] = a[hld.seq[i]];

		SegmentTree seg(w);

		auto change = [&](int u, int x) -> void
		{
			a[u] += x;
			seg.rangeAdd(1, hld.in[u], hld.in[u], x);
		};

		vector<int> add(n + 1);
		auto get = [&](int u)
		{
			i64 ans = a[u];
			if(u != 1)
			{
				int fa = hld.fa[u];
				if(u != hld.adj[fa][0]) ans += add[fa];
			}
			return ans;
		};

		while(m --)
		{
			int op; cin >>op;
			if(op & 1)
			{
				int u, v; cin >>u >>v;
				i64 res = -inf;
				while(hld.top[u] != hld.top[v])
				{
					if(hld.dep[hld.top[u]] < hld.dep[hld.top[v]]) swap(u, v);

					int l = hld.in[hld.top[u]] + 1, r = hld.in[u];
					res = max(res, seg.max_query(1, l, r));
					res = max(res, get(hld.top[u]));

					u = hld.fa[hld.top[u]];
				}
				if(hld.dep[u] > hld.dep[v]) swap(u, v);
				int l = hld.in[u] + 1, r = hld.in[v];
				res = max(res, seg.max_query(1, l, r));
				res = max(res, get(u));
				cout <<res <<endl;
			}
			else
			{
				int u, x; cin >>u >>x;
				if(u != 1) change(hld.fa[u], x);
				if(hld.adj[u].size()) change(hld.adj[u][0], x);
				add[u] += x;
			}
		}	
	}
	return 0;
}