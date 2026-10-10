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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10;
constexpr i64 mod = (1LL << 61) - 1;

i64 add(i64 a, i64 b)
{
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

i64 mul(i64 a, i64 b)
{
	i128 c = (i128)a * b;
	i64 res = (c >> 61) + (c & mod);
	if(res >= mod) res -= mod;
	return res;
}

i64 qpow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = mul(res, a);

		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

array<i64, 2> base, p[N], invp[N];

void initial()
{
	uniform_int_distribution<i64> dist(2, mod - 2);
	for(int k = 0; k < 2; k ++)
	{
		base[k] = dist(rng);
		i64 inv = qpow(base[k], mod - 2);

		p[0][k] = invp[0][k] = 1;
		for(int i = 1; i < N; i ++)
		{
			p[i][k] = mul(p[i - 1][k], base[k]);
			invp[i][k] = mul(invp[i - 1][k], inv);
		}
	}
}

struct SegmentTree
{
	struct Info
	{
		i64 mn, mx;
		array<i64, 2> h, rh;

		friend Info operator+(const Info &a, const Info &b)
		{
			Info c;
			c.mn = min(a.mn, b.mn);
			c.mx = max(a.mx, b.mx);
			for(int k = 0; k < 2; k ++)
			{
				c.h[k] = add(a.h[k], b.h[k]);
				c.rh[k] = add(a.rh[k], b.rh[k]);
			}
			return c;
		}
	};

	struct Tag
	{
		i64 lazy = 0;
		array<i64, 2> mul{1, 1}, rmul{1, 1};
	};

	int n;
	vector<int> w;
	vector<Info> tr;
	vector<Tag> tag;

	SegmentTree(vector<int> &a)
	{
		n = a.size() - 1;
		w = a;
		tr.resize(4 * n + 10);
		tag.resize(4 * n + 10);
		build(1, 1, n);
	}

	void apply_add(int u, const Tag &v)
	{
		tr[u].mx += v.lazy;
		tr[u].mn += v.lazy;
		tag[u].lazy += v.lazy;

		for(int k = 0; k < 2; k ++)
		{
			tr[u].h[k] = mul(tr[u].h[k], v.mul[k]);
			tr[u].rh[k] = mul(tr[u].rh[k], v.rmul[k]);
			tag[u].mul[k] = mul(tag[u].mul[k], v.mul[k]);
			tag[u].rmul[k] = mul(tag[u].rmul[k], v.rmul[k]);
		}
	}

	void pushup(int u)
	{
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}

	void pushdown(int u)
	{
		if(tag[u].lazy == 0) return ;

		apply_add(u << 1, tag[u]);
		apply_add(u << 1 | 1, tag[u]);

		tag[u] = {};
	}

	void build(int u, int l, int r)
	{
		if(l == r)
		{
			tr[u].mn = tr[u].mx = w[l];
			tr[u].h = p[w[l]];
			tr[u].rh = invp[w[l]];
			return ;
		}

		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}

	void rangeAdd(int u, int l, int r, int ql, int qr, int x)
	{
		if(l >= ql && r <= qr)
		{
			apply_add(u, Tag{x, p[x], invp[x]});
			return ;
		}

		pushdown(u);

		int mid = l + r >> 1;
		if(ql <= mid) rangeAdd(u << 1, l, mid, ql, qr, x);
		if(qr >= mid + 1) rangeAdd(u << 1 | 1, mid + 1, r, ql, qr, x);
		pushup(u);
	}

	void rangeAdd(int ql, int qr, int x)
	{
		if(!x) return ;
		return rangeAdd(1, 1, n, ql, qr, x);
	}

	Info query(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return tr[u];

		pushdown(u);
		int mid = l + r >> 1;

		if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
		if(qr < mid + 1) return query(u << 1, l, mid, ql, qr);
		return query(u << 1, l, mid, ql, qr) + query(u << 1 | 1, mid + 1, r, ql, qr);
	}

	Info query(int ql, int qr)
	{
		return query(1, 1, n, ql, qr);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	initial();

	SegmentTree seg(a);
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int l, r, x; cin >>l >>r >>x;
			seg.rangeAdd(l, r, x);
		}
		else
		{
			int l, r; cin >>l >>r;
			auto res = seg.query(l, r);
			i64 s = res.mn + res.mx;
			bool f = true;
			for(int k = 0; k < 2; k ++)
			{
				if(res.h[k] != mul(qpow(base[k], s), res.rh[k]))
				{
					f = false;
					break;
				}
			}
			cout <<(f ? "YES" : "NO") <<endl;
		}
	}
	return 0;
}
