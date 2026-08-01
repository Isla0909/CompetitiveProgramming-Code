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

struct HLD
{
	int n;
	vector<int> siz, top, dep, fa, in, out, seq;
	vector<vector<int>> adj;
	int cur;

	void initial(int n)
	{
		this->n = n;
		siz.resize(n + 1);
		top.resize(n + 1);
		dep.resize(n + 1);
		fa.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
		seq.resize(n + 1);//seq[i]表示时间戳为i的节点是谁
		cur = 1;
		adj.assign(n + 1, {});
	}

	HLD() {}
	HLD(int n)
	{
		initial(n);
	}

	void add(int a, int b)
	{
		adj[a].push_back(b);
	}

	void dfs1(int u)
	{
		if(fa[u] != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa[u]));

		siz[u] = 1;
		for(auto &v : adj[u])//记得加引用, 因为要实打实地交换adj中的位置
		{
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];

			if(siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
		}
	}
	//在dfs1后每个节点的重儿子就是adj[u][0], 在此没有用别的数组再维护
	void dfs2(int u)
	{
		in[u] = cur ++;//时间戳从1开始
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
		dep[root] = 0;
		fa[root] = -1;
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

	int jump(int u, int k)//节点u向上跳k步的节点
	{
		assert(dep[u] >= k);

		int d = dep[u] - k;//dep[v]
		while(dep[top[u]] > d) u = fa[top[u]];

		//重链的dfs序连续: dep[u] - dep[v] = in[u] - in[v]
		//in[v] = in[u] + d - dep[u]
		return seq[in[u] + d - dep[u]];
	}

	bool isAncester(int u, int v)
	{
		return in[u] <= in[v] && out[u] > in[v];
	}

	int rootedParent(int u, int v)//以u为根时，v的父节点是谁？
	{
		swap(u, v);//以v为根时, u的父节点是谁
		if(u == v) return u;
		
		if(!isAncester(u, v))
		{
			return fa[u];
		}

		auto it = upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {return in[x] < in[y]; })  - 1;
		return *it;
	}

	int rootedSize(int u, int v)
	{
		if(u == v) return n;

		if(!isAncester(v, u))
		{
			return siz[v];
		}
		return n - siz[rootedParent(u, v)];
	}

	int rootedLca(int a, int b, int c)//以c为根时, a和b的lca
	{
		return lca(a, b) ^ lca(b, c) ^ lca(c, a);
	}

};

struct SegmentTree
{
	struct node
	{
		int l, r;
		i64 sum, val1, val2, lazy;//val1, val2分别是区间的最大最小值
		bool f;
		i64 set_lazy;
	};
	vector<int> w;
	vector<node> tree;

	void pushup(int u)
	{
		auto pushup = [&](node &p, node &l, node &r) -> void
		{
			p.sum = l.sum + r.sum;
			p.val1 = max(l.val1, r.val1);
			p.val2 = min(l.val2, r.val2);
		};
		pushup(tree[u], tree[u << 1], tree[u << 1 | 1]);
	}

	void initial(int n)
	{
		w.resize(n + 1);
		tree.resize(4 * n + 1);

		auto build = [this](auto &&self, int u, int l, int r) -> void
		{
			if(l == r)
			{
				tree[u] = {l, r, w[l], w[l], w[l], 0, false, -inf};
				return ;
			}
			tree[u] = {l, r, 0, 0, 0, 0, false, -inf};
			int mid = l + r >> 1;
			self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
			pushup(u);
		};
		build(build, 1, 1, n);
	}

	SegmentTree() {}
	SegmentTree(int n)
	{
		initial(n);
	}
	SegmentTree(vector<int> a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		initial(n);
	}

	void apply_set(node &u, i64 set_lazy)
	{
		u.sum = 1LL * (u.r - u.l + 1) * set_lazy;
		u.val1 = u.val2 = u.set_lazy = set_lazy;
		u.f = true;
		u.lazy = 0;
	}

	void apply_add(node &u, i64 lazy)
	{
		if(u.f)
		{
			u.set_lazy += lazy;
			u.sum += 1LL * (u.r - u.l + 1) * lazy;
			u.val1 += lazy, u.val2 += lazy;
		}
		else
		{
			u.sum += 1LL * (u.r - u.l + 1) * lazy;
			u.val1 += lazy, u.val2 += lazy;
			u.lazy += lazy;
		}
	}

	void pushdown(int u)
	{
		if(tree[u].f)//优先处理赋值操作
		{
			apply_set(tree[u << 1], tree[u].set_lazy);
			apply_set(tree[u << 1 | 1], tree[u].set_lazy);
			tree[u].f = false;
		}
		if(tree[u].lazy == 0) return ;
		apply_add(tree[u << 1], tree[u].lazy);
		apply_add(tree[u << 1 | 1], tree[u].lazy);
		tree[u].lazy = 0;
	}

	void rangeSet(int u, int l, int r, int x)
	{
		if(tree[u].l >= l && tree[u].r <= r)
		{
			apply_set(tree[u], x);
			return ;
		}

		pushdown(u);
		int mid = tree[u].l + tree[u].r >> 1;
		if(l <= mid) rangeSet(u << 1, l, r, x);
		if(r >= mid + 1) rangeSet(u << 1 | 1, l, r, x);
		pushup(u);
	}

	void rangeAdd(int u, int l, int r, int x)
	{
		if(tree[u].l >= l && tree[u].r <= r)
		{
			apply_add(tree[u], x);
			return ;
		}

		pushdown(u);

		int mid = tree[u].l + tree[u].r >> 1;
		if(l <= mid) rangeAdd(u << 1, l, r, x);
		if(r >= mid + 1) rangeAdd(u << 1 | 1, l, r, x);
		pushup(u);
	}

	i64 max_query(int u, int l, int r)
	{
		if(tree[u].l >= l && tree[u].r <= r) return tree[u].val1;

		pushdown(u);
		int mid = tree[u].l + tree[u].r >> 1;

		i64 res = -inf;
		if(l <= mid) res = max(res, max_query(u << 1, l, r));
		if(r >= mid + 1) res = max(res, max_query(u << 1 | 1, l, r));
		return res;
	}

	i64 min_query(int u, int l, int r)
	{
		if(tree[u].l >= l && tree[u].r <= r) return tree[u].val2;

		pushdown(u);
		int mid = tree[u].l + tree[u].r >> 1;

		i64 res = inf;
		if(l <= mid) res = min(res, min_query(u << 1, l, r));
		if(r >= mid + 1) res = min(res, min_query(u << 1 | 1, l, r));
		return res;
	}

	i64 rangeSum(int u, int l, int r)
	{
		if(tree[u].l >= l && tree[u].r <= r) return tree[u].sum;

		pushdown(u);
		int mid = tree[u].l + tree[u].r >> 1;

		i64 res = 0;
		if(l <= mid) res += rangeSum(u << 1, l, r);
		if(r >= mid + 1) res += rangeSum(u << 1 | 1, l, r);
		return res;
	}

	int find_first(int u, int ql, int qr, i64 x)//查询区间第一个大于x的数的下标
	{
		//无交集返回-1
		if(tree[u].l > qr || tree[u].r < ql) return -1;

		//完美包含但不满足返回-1
		if(tree[u].l >= ql && tree[u].r <= qr && tree[u].val1 <= x) return -1;

		if(tree[u].l == tree[u].r) return tree[u].l;

		pushdown(u);

		int c = find_first(u << 1, ql, qr, x);
		if(c != -1) return c;
		return find_first(u << 1 | 1, ql, qr, x);
	}

	int find_last(int u, int ql, int qr, i64 x)//查询区间最后一个小于等于x的数的下标
	{
		//无交集返回-1
		if(tree[u].l > qr || tree[u].r < ql) return -1;

		//完美包含但不满足返回-1
		if(tree[u].l >= ql && tree[u].r <= qr && tree[u].val2 > x) return -1;

		if(tree[u].l == tree[u].r) return tree[u].l;

		pushdown(u);

		int c = find_last(u << 1 | 1, ql, qr, x);
		if(c != -1) return c;
		return find_last(u << 1, ql, qr, x);
	}
};
//注:find_first/last中不满足条件就是对条件取反, 并注意对val1, val2进行修改  

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	HLD hld(n);
	for(int i = 2; i <= n; i ++)
	{
		int x; cin >>x;
		x ++;
		hld.add(i, x), hld.add(x, i);
	}
	hld.work();

	vector<int> w(n + 1);
	SegmentTree seg(w);

	int q; cin >>q;
	while(q --)
	{
		string s; cin >>s;
		if(s == "install")
		{
			int x; cin >>x;
			x ++;

			int u = 1, v = x, res = 0;
			while(hld.top[u] != hld.top[v])
			{
				if(hld.dep[hld.top[u]] < hld.dep[hld.top[v]]) swap(u, v);

				int l = hld.in[hld.top[u]], r = hld.in[u];

				res += r - l + 1 - seg.rangeSum(1, l, r);
				seg.rangeSet(1, l, r, 1);
				u = hld.fa[hld.top[u]];
			}
			if(hld.dep[u] > hld.dep[v]) swap(u, v);
			int l = hld.in[u], r = hld.in[v];
			res += r - l + 1 - seg.rangeSum(1, l, r);
			seg.rangeSet(1, l, r, 1);
			cout <<res <<endl;
		}	
		else
		{
			int x; cin >>x;
			x ++;

			int u = x;
			int l = hld.in[u], r = hld.in[u] + hld.siz[u] - 1;
			cout <<seg.rangeSum(1, l, r) <<endl;
			seg.rangeSet(1, l, r, 0);
		}
	}
	return 0;
}
