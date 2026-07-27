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

struct SegmentTree
{
	struct node
	{
		int l, r;
		i64 sum;//val1, val2分别是区间的最大最小值
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
				tree[u] = {l, r, w[l], false, -inf};
				return ;
			}
			tree[u] = {l, r, 0, false, -inf};
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
	SegmentTree(vector<int> &a)
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
		u.f = true;
		u.set_lazy = set_lazy;
	}

	void pushdown(int u)
	{
		if(tree[u].f)//优先处理赋值操作
		{
			apply_set(tree[u << 1], tree[u].set_lazy);
			apply_set(tree[u << 1 | 1], tree[u].set_lazy);
			tree[u].f = false;
		}
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
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x; cin >>n >>m >>x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<array<int, 3>> v(m);
	for(int i = 0; i < m; i ++)
	{
		int op, l, r; cin >>op >>l >>r;
		v[i] = {op, l, r};
	}

	vector<int> b(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++)
		b[i] = (a[i] >= x), c[i] = (a[i] > x);

	auto change = [&](vector<int> &f) -> void
	{
		SegmentTree seg(f);
		for(auto [op, l, r] : v)
		{
			int cnt = seg.rangeSum(1, l, r);
			if(cnt == 0 || cnt == r - l + 1) continue;
			if(op == 2)
			{
				if(l + cnt - 1 >= l) seg.rangeSet(1, l, l + cnt - 1, 1);
				if(l + cnt <= r) seg.rangeSet(1, l + cnt, r, 0);
			} 
			else
			{
				if(r - cnt + 1 <= r) seg.rangeSet(1, r - cnt + 1, r, 1);
				if(l <= r - cnt) seg.rangeSet(1, l, r - cnt, 0);
			}
		}
		for(int i = 1; i < f.size(); i ++)
			f[i] = seg.rangeSum(1, i, i);
	};

	change(b), change(c);
	for(int i = 1; i <= n; i ++)
		if(b[i] != c[i])
		{
			cout <<i <<endl;
			break;
		}

	return 0;
}
