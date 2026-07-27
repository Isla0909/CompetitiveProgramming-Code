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
		int lval, rval;
		int cnt;
		int pre, suf;
		int ans;
		bool tag;
		int set_val;
	};
	vector<int> w;
	vector<node> tr;

	void pushup(int u)
	{
		auto pushup = [&](node &p, node &l, node &r) -> void
		{
			if(l.cnt == 0)
			{
				p.lval = r.lval, p.rval = r.rval;
				p.cnt = r.cnt;
				p.pre = r.pre, p.suf = r.suf, p.ans = r.ans;
				return ;
			}
			if(r.cnt == 0) 
			{
				p.lval = l.lval, p.rval = l.rval;
				p.cnt = l.cnt;
				p.pre = l.pre, p.suf = l.suf, p.ans = l.ans;
				return ;
			}

			p.cnt = l.cnt + r.cnt;
			p.lval = l.lval, p.rval = r.rval;

			p.pre = l.pre;
			if(l.pre == l.cnt && l.rval == r.lval) p.pre = l.cnt + r.pre;

			p.suf = r.suf;
			if(r.suf == r.cnt && l.rval == r.lval) p.suf = r.suf + l.suf;

			p.ans = max(l.ans, r.ans);
			if(l.rval == r.lval) p.ans = max(p.ans, l.suf + r.pre);
		};
		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}
	
	void initial(int n)
	{
		w.resize(n + 1);
		tr.resize(4 * n + 1);

		auto build = [this](auto &&self, int u, int l, int r)
		{
			tr[u] = {l, r};
			if(l == r)
			{
				tr[u].tag = false, tr[u].set_val = 0;
				if(w[l] == 0)
				{
					tr[u].lval = tr[u].rval = 0;
					tr[u].cnt = 0;
					tr[u].pre = tr[u].suf = tr[u].ans = 0;
				}
				else
				{
					tr[u].lval = tr[u].rval = w[l];
					tr[u].cnt = 1;
					tr[u].pre = tr[u].suf = tr[u].ans = 1;
				}
				return ;
			}
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
	SegmentTree(const vector<int> &a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		initial(n);
	}

	void apply_set(int u, int val)
	{
		tr[u].tag = true;
		tr[u].set_val = val;

		if(val == 0)
		{
			tr[u].lval = tr[u].rval = 0;
			tr[u].cnt = 0;
			tr[u].pre = tr[u].suf = tr[u].ans = 0;
		}
		else
		{
			int len = tr[u].r - tr[u].l + 1;
			tr[u].lval = tr[u].rval = val;
			tr[u].cnt = len;
			tr[u].pre = tr[u].suf = tr[u].ans = len;
		}
	}

	void pushdown(int u)
	{
		if(!tr[u].tag) return  ;
		apply_set(u << 1 , tr[u].set_val);
		apply_set(u << 1 | 1, tr[u].set_val);
		tr[u].tag = false;
	}

	void rangeSet(int u, int l, int r, int val)
	{
		if(l > r) return ;

		if(tr[u].l >= l && tr[u].r <= r)
		{
			apply_set(u, val);
			return ;
		}
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) rangeSet(u << 1, l, r, val);
		if(r >= mid + 1) rangeSet(u << 1 | 1, l, r, val);
		pushup(u);
	}

	void pointSet(int u, int pos, int val)
	{
		if(tr[u].l == tr[u].r)
		{
			apply_set(u, val);
			return ;
		}

		pushdown(u);

		int mid = tr[u].l + tr[u].r >> 1;
		if(pos <= mid) pointSet(u << 1, pos, val);
		else pointSet(u << 1 | 1, pos, val);
		pushup(u);
	}

	int query()
	{
		return tr[1].ans;
	}

};

struct DSU
{
	vector<int> p, siz;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);
	}

	DSU(int n)
	{
		initial(n);
	}

	int find(int x)
	{
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	void merge(int a, int b)
	{
		a = find(a), b = find(b);
		if(a == b) return ;

		siz[a] += siz[b];
		p[b] = a;
	}

	int size(int x)
	{
		return siz[find(x)];
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		vector<int> a(n + 1);
		set<int> s;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(a[i]) s.insert(i);
		}

		vector<int> f(n + 1);
		if(s.size())
		{
			auto it = s.begin();
			while(it != s.end())
			{
				auto to = next(it);
				if(to != s.end()) f[*it] = *to - *it;
				else f[*it] = 0;
				it = to;
			}
		}

		SegmentTree seg(f);
		DSU dsu(n + 1);
		dsu.p[n + 1] = n + 1;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == 1) dsu.p[i] = i + 1;
			else dsu.p[i] = i;
		}

		while(q --)
		{
			int l, r; cin >>l >>r;

			int p = 0;
			auto itl = s.lower_bound(l);
			if(itl != s.begin())
			{
				auto itp = prev(itl);
				p = *itp;
			}

			int nex = 0;
			auto itr = s.upper_bound(r);
			if(itr != s.end()) nex = *itr;

			int x = dsu.find(l);
			while(x <= r)
			{
				s.insert(x);
				dsu.p[x] = x + 1;
				x = dsu.find(x);
			}

			if(l <= r - 1) seg.rangeSet(1, l, r - 1, 1);

			if(p) seg.pointSet(1, p, l - p);
			if(nex) seg.pointSet(1, r, nex - r);

			cout <<max(1, seg.query() + 1) <<endl;
		}
	}
	return 0;
}
