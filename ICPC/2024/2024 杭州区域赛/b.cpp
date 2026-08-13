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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const u64 full = (1ULL << 63) - 1;

struct Info
{
	u64 val, state;

	Info operator+(const Info &rhs) const
	{
		Info res;
		res.val = val & rhs.val;
		res.state = (val & rhs.state) | (state & rhs.val);
		return res;
	}

	Info &operator+=(const Info &rhs)
	{
		*this = *this + rhs;
		return *this;
	}
}tr[N << 2];

int n, q;
u64 a[N];
u64 tag[N << 2];

void pushup(int u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void apply(int u, int l, int r, u64 x)
{
	tr[u].val &= x;
	if(l == r) tr[u].state = (~tr[u].val) & full;
	else tr[u].state &= x;
	tag[u] &= x;
}

void pushdown(int u, int l, int r)
{
	if(tag[u] == full) return ;
	int mid = l + r >> 1;
	apply(u << 1, l, mid, tag[u]), apply(u << 1 | 1, mid + 1, r, tag[u]);

	tag[u] = full;
}

void build(int u, int l, int r)
{
	tag[u] = full;		
	if(l == r)
	{
		tr[u].val = a[l];
		tr[u].state = (~a[l]) & full;
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);

	pushup(u);
}

void rangeAnd(int u, int l, int r, int ql, int qr, u64 x)
{
	if(l >= ql && r <= qr)
	{
		apply(u, l, r, x);
		return ;
	}

	pushdown(u, l, r);
	int mid = l + r >> 1;

	if(ql <= mid) rangeAnd(u << 1, l, mid, ql, qr, x);
	if(qr >= mid + 1) rangeAnd(u << 1 | 1, mid + 1, r, ql, qr, x);

	pushup(u);
}

void rangeAnd(int ql, int qr, u64 x)
{
	return rangeAnd(1, 1, n, ql, qr, x);
}

void modify(int u, int l, int r, int pos, u64 x)
{
	if(l == r)
	{
		tr[u].val = x;
		tr[u].state = (~x) & full;
		return ;
	}
	pushdown(u, l, r);

	int mid = l + r >> 1;
	if(pos <= mid) modify(u << 1, l, mid, pos, x);
	else modify(u << 1 | 1, mid + 1, r, pos, x);

	pushup(u);
}

void modify(int pos, u64 x)
{
	modify(1, 1, n, pos, x);
}

Info query(int u, int l, int r, int ql, int qr)
{
	if(l >= ql && r <= qr) return tr[u];
	pushdown(u, l, r);
	int mid = l + r >> 1;
	
	Info res{full, 0};
	if(ql <= mid) res += query(u << 1, l, mid, ql, qr);
	if(qr >= mid + 1) res += query(u << 1 | 1, mid + 1, r, ql, qr);
	return res;
}

Info query(int ql, int qr)
{
	return query(1, 1, n, ql, qr);
}

int find_first(int u, int l, int r, int ql, int qr, int d)
{
	if(ql > r || qr < l) return -1;
	if(l >= ql && r <= qr && (tr[u].val >> d & 1ULL)) return -1;

	if(l == r) return l;

	pushdown(u, l, r);

	int mid = l + r >> 1;
	int p = find_first(u << 1, l, mid, ql, qr, d);
	if(p != -1) return p;
	return find_first(u << 1 | 1, mid + 1, r, ql, qr, d);
}

int find_first(int ql, int qr, int d)
{
	return find_first(1, 1, n, ql, qr, d);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >>n >>q;
	for(int i = 1; i <= n; i ++) cin >>a[i];

	build(1, 1, n);

	while(q --)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int l, r; u64 x; cin >>l >>r >>x;
			rangeAnd(l, r, x);
		}
		else if(op == 2)
		{
			int pos; u64 x; cin >>pos >>x;
			modify(pos, x);
		}
		else
		{
			int l, r; cin >>l >>r;
			auto [val, state] = query(l, r);
			if(!state) cout <<val <<endl;
			else
			{
				int d = -1;
				for(int j = 62; j >= 0 && d == -1; j --)
					if(state >> j & 1ULL)
						d = j;
				int pos = find_first(l, r, d);
				u64 res = full;
				if(pos - 1 >= l) res &= query(l, pos - 1).val;
				if(pos + 1 <= r) res &= query(pos + 1, r).val;
				cout <<res <<endl;
			}
		}
	}
	return 0;
}