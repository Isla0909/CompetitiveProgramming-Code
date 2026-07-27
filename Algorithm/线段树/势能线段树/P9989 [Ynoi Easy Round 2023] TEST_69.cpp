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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 lcm(i64 a, i64 b)
{
	i64 c = __gcd(a, b);
	return min((i128)inf * 2, (i128) a * b / c);
}

struct SegmentTree
{
	struct node
	{
		int l, r;
		i64 sum, lcm;
	};

	vector<i64> w;
	vector<node> tr;
	
	void pushup(int u)
	{
		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void pushup(node &u, node &l, node &r)
	{
		u.sum = l.sum + r.sum;
		u.lcm = lcm(l.lcm, r.lcm);
	}

	SegmentTree(vector<i64> &a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		tr.resize(4 * n + 1);

		auto build = [this](auto &&self, int u, int l, int r)
		{
			if(l == r)
			{
				tr[u] = {l, r, w[l], w[l]};
				return ;
			}
			tr[u] = {l, r};
			int mid = l + r >> 1;
			self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
			pushup(u);
		};
		build(build, 1, 1, n);
	}

	void modify(int u, int l, int r, i64 x)
	{
		if(x % tr[u].lcm == 0) return ;

		if(tr[u].l == tr[u].r)
		{
			i64 c = __gcd(tr[u].sum, x);
			tr[u].sum = tr[u].lcm = c;
			return ;
		}

		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r, x);
		if(r >= mid + 1) modify(u << 1 | 1, l, r, x);
		pushup(u);
	}

	u32 query(int u, int l, int r)
	{
		if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

		int mid = tr[u].l + tr[u].r >> 1;

		u32 res = 0;
		if(l <= mid) res += query(u << 1, l, r);
		if(r >= mid + 1) res += query(u << 1 | 1, l, r);
		return res;
	}

};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	SegmentTree seg(a);	
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int l, r; i64 x; cin >>l >>r >>x;
			seg.modify(1, l, r, x);
		}
		else
		{
			int l, r; cin >>l >>r;
			cout <<seg.query(1, l, r) <<endl;
		}
	}
	return 0;
}
