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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct PresidentTree
{
	int idx = 0;
	int root[N];

	struct node
	{
		int l, r;
		int cnt;
	}tr[4 * N + 35 * N];

	void modify(int &u, int v, int l, int r, int x, int c)
	{
		u = ++ idx;
		tr[u] = tr[v];
		tr[u].cnt += c;

		if(l == r) return ;
		int mid = l + r >> 1;
		if(x <= mid) modify(tr[u].l, tr[v].l, l, mid, x, c);
		else modify(tr[u].r, tr[v].r, mid + 1, r, x, c);
	}

	int query(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return tr[u].cnt;

		int mid = l + r >> 1;
		int res = 0;
		if(ql <= mid) res = query(tr[u].l, l, mid, ql, qr);
		if(qr >= mid + 1) res += query(tr[u].r, mid + 1, r, ql, qr);
		return res; 
	};
};

int lst[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(lst, -1, sizeof lst);

	PresidentTree tr;
	int n; cin >>n;

	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		if(lst[x] == -1)
		{
			tr.modify(tr.root[i], tr.root[i - 1], 1, n, i, 1);
			lst[x] = i;
		}
		else
		{
			int pos = lst[x];
			tr.modify(tr.root[i], tr.root[i - 1], 1, n, pos, -1);
			tr.modify(tr.root[i], tr.root[i], 1, n, i, 1);
			lst[x] = i;
		}
	}

	int q; cin >>q;
	while(q --)
	{
		int l, r; cin >>l >>r;
		cout <<tr.query(tr.root[r], 1, n, l, r) <<endl;
	}
	return 0;
}