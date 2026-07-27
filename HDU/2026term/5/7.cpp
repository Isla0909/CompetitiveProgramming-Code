#pragma GCC optimize ("O2")
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

constexpr int N = 2e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

i64 ans[N];

struct SegmentTree
{
	struct node
	{
		int l, r;
		int val;
		i64 lazy;
		bool f;
		int set_lazy;
	};

	vector<int> w;
	vector<node> tr;

	SegmentTree(vector<int> &a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		tr.resize(4 * n + 10);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		build(1, 1, n);
	}

	void pushup(node &u, node &l, node &r)
	{
		if(l.val != r.val) u.val = -1;
		else u.val = r.val;
	}

	void pushup(int u)
	{
		pushup(tr[u], tr[u << 1], tr[u << 1 |1]);
	}

	void build(int u, int l, int r)
	{
		tr[u].l = l, tr[u].r = r;
		tr[u].lazy = 0;
		tr[u].f = false;
		tr[u].set_lazy = -INF;
		if(l == r)
		{
			tr[u].val = w[l];
			return ;
		}

		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}

	void apply_add(int u, int x)
	{
		tr[u].lazy += x;
		if(tr[u].val != -1)
		{
			int len = tr[u].r - tr[u].l + 1;
			int c = tr[u].val;
			ans[c] += 1LL * len * tr[u].lazy;
			tr[u].lazy = 0;
		}
	}

	void clear(int u)
	{
		if(tr[u].val != -1) return ;

		pushdown(u);
		if(tr[u].l != tr[u].r)
		{
			clear(u << 1);
			clear(u << 1 | 1);
			pushup(u);
		}
	}

	void apply_set(int u, int set_lazy)
	{
		tr[u].val = tr[u].set_lazy = set_lazy;
		tr[u].f = 1;
		tr[u].lazy = 0;
	}

	void pushdown(int u)
	{
		if(tr[u].f)
		{
			apply_set(u << 1, tr[u].set_lazy);
			apply_set(u << 1 | 1, tr[u].set_lazy);
			tr[u].f = 0;
		}
		if(tr[u].lazy)
		{
			apply_add(u << 1, tr[u].lazy);
			apply_add(u << 1 | 1, tr[u].lazy);
			tr[u].lazy = 0;
		}
	}

	void rangeSet(int u, int l, int r, int x)
	{
		if(tr[u].l >= l && tr[u].r <= r)
		{
			clear(u);
			apply_set(u, x);
			return ;
		}
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) rangeSet(u << 1, l, r, x);
		if(r >= mid + 1) rangeSet(u << 1 | 1, l, r, x);
		pushup(u);
	}

	void rangeAdd(int u, int l, int r, int x)
	{
		if(tr[u].l >= l && tr[u].r <= r)
		{
			apply_add(u, x);
			return ;
		}
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) rangeAdd(u << 1, l, r, x);
		if(r >= mid + 1) rangeAdd(u << 1 | 1, l, r, x);
		pushup(u);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, q; cin >>n >>m >>q;

		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		SegmentTree seg(a);
		while(q --)
		{
			int op, l, r, x; cin >>op >>l >>r >>x;
			if(op & 1) seg.rangeSet(1, l, r, x);
			else seg.rangeAdd(1, l, r, x);
		}

		seg.clear(1);
		for(int i = 1; i <= m; i ++)
		{
			cout <<ans[i] <<" \n"[i == m];
			ans[i] = 0;
		}
	}
	return 0;
}
