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
		int x;
	};
	vector<int> w;
	vector<node> tr;

	void pushup(int u)
	{
		auto pushup = [&](node &p, node &l, node &r)
		{
			p.x = __gcd(l.x, r.x);
		};
		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void initial(int n)
	{
		w.resize(n + 1);
		tr.resize(4 * n + 1);

		auto build = [this](auto &&self, int u, int l, int r) -> void
		{
			if(l == r)
			{
				tr[u] = {l, r, w[l]};
				return ;
			}
			tr[u] = {l, r};
			int mid = l + r >> 1;
			self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
			pushup(u);
		};
		build(build, 1, 1, n);
	}

	SegmentTree (vector<int> a)
	{
		int n = a.size() - 1;
		w.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			w[i] = a[i];
		initial(n);
	}

	void modify(int u, int pos, int x)
	{
		if(tr[u].l == pos && tr[u].r == pos)
		{
			tr[u].x = x;
			w[pos] = x;
			return ;
		}
		int mid = tr[u].l + tr[u].r >> 1;
		if(pos <= mid) modify(u << 1, pos, x);
		else modify(u << 1 | 1, pos, x);
		pushup(u);
	}

	int gcd_query(int u, int l, int r)
	{
		if(tr[u].l >= l && tr[u].r <= r) return tr[u].x;

		int mid = tr[u].l + tr[u].r >> 1;

		int res = 0;
		if(l <= mid) res = __gcd(res, gcd_query(u << 1, l, r));
		if(r >= mid + 1) res = __gcd(res, gcd_query(u << 1 | 1, l, r));
		return res;
	}
};

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> div(N);
	for(int i = 1; i < N; i ++)
		for(int j = 1; j * i < N; j ++)
			div[i * j] ++;

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		vector<int> a(n + 2), b(n + 2);
		for(int i = 1; i <= n; i ++) cin >>b[i];
		b[n + 1] = 2e9 + 1;


		for(int i = 1; i <= n; i ++)
			if(b[i] > b[i + 1]) a[i] = i;

		//tell(1, div);

		SegmentTree seg(a);
		int res = seg.gcd_query(1, 1, n + 1);
		cout <<(res ? div[res] : n) <<endl;
		while(q --)
		{
			int p, x; cin >>p >>x;
			b[p] = x;
			for(int i = p - 1; i <= p && i <= n; i ++)
			{
				if(b[i] > b[i + 1]) seg.modify(1, i, i);
				else seg.modify(1, i, 0);
			}
			res = seg.gcd_query(1, 1, n + 1);
			//cout <<"gcd " <<res <<endl;
			cout <<(res ? div[res] : n) <<endl;

			// tell(1, b);
			// tell(1, seg.w);
		}
	}
	return 0;
}