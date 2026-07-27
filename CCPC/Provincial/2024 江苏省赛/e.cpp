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
	int idx = 0;
	int root[N];

	struct node
	{
		int l, r;
		int cnt;
	}tr[4 * N + 17 * 17 * N];

	void modify(int &u, int v, int l, int r, int x)
	{
		u = ++idx;
		tr[u] = tr[v];
		tr[u].cnt ++;

		if(l == r) return ;

		int mid = l + r >> 1;
		if(x <= mid) modify(tr[u].l, tr[v].l, l, mid, x);
		else modify(tr[u].r, tr[v].r, mid + 1, r, x);
	}

	int kth(int u, int v, int l, int r, int k)
	{
		if(l == r) return l;

		int c = tr[tr[u].l].cnt - tr[tr[v].l].cnt;
		int mid = l + r >> 1;
		if(k <= c) return kth(tr[u].l, tr[v].l, l, mid, k);
		else return kth(tr[u].r, tr[v].r, mid + 1, r, k - c);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	static PresidentTree tr; 
	int m = 100000;
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		tr.root[i] = tr.root[i - 1];

		int x = a[i], cnt = 0;
		while(x)
		{
			tr.modify(tr.root[i], tr.root[i], 1, m, x);
			x >>= 1;
			cnt ++;
		}
		pre[i] = pre[i - 1] + cnt;
	}
	while(q --)
	{
		int l, r, k; cin >>l >>r >>k;
		int tot = pre[r] - pre[l - 1];
		if(tot <= k) cout <<0 <<endl;
		else cout <<tr.kth(tr.root[r], tr.root[l - 1], 1, m, tot + 1 - (k + 1)) <<endl;
	}
	return 0;
}
