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

struct SegmentTree
{
	struct node
	{
		int l, r;
		int lval, rval;
		int lcnt, rcnt, v;
	};
	vector<int> w;
	vector<node> tree;


	SegmentTree() {}
	SegmentTree(int n)
	{
		initial(n);
	}
	SegmentTree(const vector<int> &a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		initial(n);
	}

	void pushup(node &u, node &l, node &r)
	{
		u.lval = l.lval, u.rval = r.rval;
		int x = 0;
		u.lcnt = l.lcnt, u.rcnt = r.rcnt;
		if(l.rval == r.lval)
		{
			x = l.rcnt + r.lcnt;
			if(l.lcnt == l.r - l.l + 1) u.lcnt = x;
			if(r.rcnt == r.r - r.l + 1) u.rcnt = x;
		}
		u.v = max(max(l.v, r.v), x);
	}

	void pushup(int u)
	{
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
				tree[u] = {l, r, w[l], w[l], 1, 1, 1};
				return ;
			}
			tree[u].l = l, tree[u].r = r;
			int mid = l + r >> 1;
			self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
			pushup(u);
		};
		build(build, 1, 1, n);
	}

	node query(int u, int l, int r)
	{
	    if(tree[u].l >= l && tree[u].r <= r) return tree[u];
	    
	    int mid = tree[u].l + tree[u].r >> 1;
	    if(r <= mid) return query(u << 1, l, r);
	    else if(l > mid) return query(u << 1 | 1, l, r);
	    else
	    {
	        auto left = query(u << 1, l, r);
	        auto right = query(u << 1 | 1, l, r);
	        node res;
	        pushup(res, left, right);
	        return res;
	    }
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	string s; cin >>s;
	s = " " + s;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		a[i] = s[i] - 'a' + 1;

	SegmentTree seg(a);
	int q; cin >>q;
	while(q --)
	{
		int l, r; cin >>l >>r;
		cout <<r - l + 1 -seg.query(1, l, r).v <<endl;
	}
	return 0;
}
