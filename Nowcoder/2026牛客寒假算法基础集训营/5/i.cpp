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
		i64 sum, lazy;
	};
	vector<i64> w;
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
				tree[u] = {l, r, w[l], 0LL};
				return ;
			}
			tree[u] = {l, r, 0LL, 0LL};
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

	void apply_add(node &u, i64 lazy)
	{
		u.sum += (u.r - u.l + 1) * lazy;
		u.lazy += lazy;
	}

	void pushdown(int u)
	{
		if(!tree[u].lazy) return ;
		apply_add(tree[u << 1], tree[u].lazy);
		apply_add(tree[u << 1 | 1], tree[u].lazy);
		tree[u].lazy = 0LL;
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

	void get(int u, vector<i64> &v)
	{
		if(tree[u].l == tree[u].r)
		{
			v[tree[u].l] = tree[u].sum;
			return ;
		}
		pushdown(u);
		get(u << 1, v), get(u << 1 | 1, v);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; i64 h; cin >>n >>m >>h;
	vector<array<int, 2>> v(m + 1);
	for(int i = 1; i <= m; i ++)
		cin >>v[i][0] >>v[i][1];

	SegmentTree seg(n);
	vector<i64> diff(n + 1);

	int now = 0;
	auto to = [&](int x) -> void
	{
		if(now < x)
		{
			for(int i = now + 1; i <= x; i ++)
			{
				auto [p, f] = v[i];
				if(p == 1) seg.rangeAdd(1, 1, 1, f);
				else if(p - f + 1 >= 1)
				{
					int l = p - f + 1, r = p;
					seg.rangeAdd(1, l, r, 1);
				}
				else
				{
					int c = f - (p - 1);
					seg.rangeAdd(1, 1, 1, c);
					int l = 2, r = p;
					seg.rangeAdd(1, l, r, 1);
				}

				int l = p + 1, r = min(n, p + f);
				// cout <<l <<" " <<r <<endl;
				if(l <= n && l <= r) seg.rangeAdd(1, l, r, -1);
			}
		}
		else
		{
			for(int i = now; i > x; i --)
			{
				auto [p, f] = v[i];
				if(p == 1) seg.rangeAdd(1, 1, 1, -f);
				else if(p - f + 1 >= 1)
				{
					int l = p - f + 1, r = p;
					seg.rangeAdd(1, l, r, -1);
				}
				else
				{
					int c = f - (p - 1);
					seg.rangeAdd(1, 1, 1, -c);
					int l = 2, r = p;
					seg.rangeAdd(1, l, r, -1);
				}

				int l = p + 1, r = min(n, p + f);
				// cout <<l <<" " <<r <<endl;
				if(l <= n && l <= r) seg.rangeAdd(1, l, r, 1);
			}
		}
		now = x;
	};

	auto check = [&](int x) -> bool
	{
		to(x);
		seg.get(1, diff);
		for(int i = 1; i <= n; i ++)
		{
			diff[i] += diff[i - 1];
			if(diff[i] > h) return true;
		}
		return false;
	};

	if(!check(m))
	{
		cout <<"No" <<endl;
		return 0;
	}

	int l = 0, r = m + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(!check(mid)) l = mid;
		else r = mid;
	}
	cout <<"Yes" <<endl;
	cout <<r <<endl;
	return 0;
}
