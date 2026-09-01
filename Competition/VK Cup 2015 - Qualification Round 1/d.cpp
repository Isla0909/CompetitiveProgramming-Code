#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

struct SegmentTree
{
	struct Info
	{
		int mn;

		Info operator+(const Info &rhs) const
		{
			Info res;
			res.mn = min(mn, rhs.mn);
			return res;
		}
		Info &operator+=(const Info &rhs)
		{
			*this = *this + rhs;
			return *this;
		}
	};

	int n;
	vector<Info> tr;

	SegmentTree(int n)
	{
		this -> n = n;
		tr.resize(4 * n + 10);
		build(1, 1, n);
	}

	void pushup(int u)
	{
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}

	void build(int u, int l, int r)
	{
		if(l == r)
		{
			tr[u].mn = INF;
			return ;
		}
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}

	void modify(int u, int l, int r, int pos, int x)
	{
		if(l == r)
		{
			assert(l == pos);
			tr[u].mn = x;
			return ;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(u << 1, l, mid, pos, x);
		else modify(u << 1 | 1, mid + 1, r, pos, x);
		pushup(u);
	}

	void modify(int pos, int x)
	{
		return modify(1, 1, n, pos, x);
	}

	int min_query(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return tr[u].mn;

		int mid = l + r >> 1;
		int res = INF;
		if(ql <= mid) res = min(res, min_query(u << 1, l, mid, ql, qr));
		if(qr >= mid + 1) res = min(res, min_query(u << 1 | 1, mid + 1, r, ql, qr));
		return res;
	}

	int min_query(int ql, int qr)
	{
		return min_query(1, 1, n, ql, qr);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<array<int, 3>> query(m);
	for(int i = 0; i < m; i ++)
	{
		int l, r; cin >>l >>r;
		query[i] = {i, l, r};
	}

	sort(query.begin(), query.end(), [&](auto &a, auto &b)
	{
		return a[2] < b[2];
	});

	vector<int> ans(m);
	SegmentTree seg(n);
	unordered_map<int, int> last;
	int now = 0;
	for(auto [id, l, r] : query)
	{
		while(now + 1 <= r)
		{
			now ++;
			int x = a[now];
			if(last.count(x))
			{
				int pos = last[x];
				seg.modify(pos, now - pos);
			}
			last[x] = now;
		}
		int res = seg.min_query(l, r);
		ans[id] = (res == INF) ? -1 : res;
	}
	for(int i = 0; i < m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}