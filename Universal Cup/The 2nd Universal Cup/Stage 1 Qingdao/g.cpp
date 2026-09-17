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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct PresidentTree
{
	struct Info
	{
		int ls, rs;
		int cnt;
	}tr[N * 20];

	int root[N];
	int idx;

	void initial()
	{
		idx = 0;
		root[0] = 0;
		tr[0] = {};
	}

	void modify(int &u, int v, int l, int r, int x)
	{
		u = ++ idx;
		tr[u] = tr[v];
		tr[u].cnt ++;

		if(l == r) return ;

		int mid = l + r >> 1;
		if(x <= mid) modify(tr[u].ls, tr[v].ls, l, mid, x);
		else modify(tr[u].rs, tr[v].rs, mid + 1, r, x);
	}

	int query(int u, int v, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return tr[u].cnt - tr[v].cnt;

		int mid = l + r >> 1;
		int res = 0;
		if(ql <= mid) res += query(tr[u].ls, tr[v].ls, l, mid, ql, qr);
		if(qr >= mid + 1) res += query(tr[u].rs, tr[v].rs, mid + 1, r, ql, qr);
		return res;
	}

	int count(int l, int r, int low, int high, int n)
	{
		if(l > r || low > high) return 0;
		return query(root[r], root[l - 1], 1, n, low, high);
	}
};

PresidentTree tree;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		tree.initial();
		int n; cin >>n;
		vector<int> a(n + 1); i64 inv = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			inv += tree.count(1, i - 1, a[i] + 1, n, n);
			tree.modify(tree.root[i], tree.root[i - 1], 1, n, a[i]);
		}


		map<int, i64> seg;
		multiset<i64> s;

		seg[0] = inv; s.insert(inv);
		seg[n + 1] = 0; s.insert(0LL);

		for(int i = 1; i <= n; i ++)
		{
			i64 z = *s.rbegin();
			cout <<z <<" \n"[i == n];

			i64 p; cin >>p;
			int pos = (int)(p ^ z);

			auto it1 = seg.upper_bound(pos);
			auto it2 = prev(it1);

			int R = it1 -> ff, L = it2 -> ff;
			i64 old = it2 -> se;
			s.extract(old);

			int crossl = tree.count(L + 1, pos - 1, a[pos] + 1, n, n);
			int crossr = tree.count(pos + 1, R - 1, 1, a[pos] - 1, n);

			//[L + 1, pos - 1]
			//[pos + 1, R - 1]
			i64 invl = 0, invr = 0, cross = 0;
			if(pos - L <= R - pos)
			{
				for(int j = L + 1; j < pos; j ++)
				{
					invl += tree.count(L + 1, j - 1, a[j] + 1, n, n);
					cross += tree.count(pos + 1, R - 1, 1, a[j] - 1, n);
				}
				invr = old - invl - cross - crossl - crossr;
			}
			else
			{
				for(int j = pos + 1; j < R; j ++)
				{
					invr += tree.count(pos + 1, j - 1, a[j] + 1, n, n);
					cross += tree.count(L + 1, pos - 1, a[j] + 1, n, n);
				}
				invl = old - invr - cross - crossl - crossr;
			}
			seg[L] = invl, seg[pos] = invr;
			s.insert(invl), s.insert(invr);
		}
	}
	return 0;
}
