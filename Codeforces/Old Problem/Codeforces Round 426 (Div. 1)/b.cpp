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

constexpr int N = 4e4 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, k;

struct Info
{
	int mx;

	Info operator+(const Info &rhs) const
	{
		Info res;
		res.mx = max(mx, rhs.mx);
		return res;
	}
}tr[N << 2];

int tag[N << 2];

void pushup(int u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void apply_add(int u, int x)
{
	tr[u].mx += x;
	tag[u] += x;
}

void pushdown(int u)
{
	if(!tag[u]) return ;

	apply_add(u << 1, tag[u]);
	apply_add(u << 1 | 1, tag[u]);
	tag[u] = 0;
}


void build(int u, int l, int r, vector<int> &dp)
{
	tag[u] = 0;
	if(l == r)
	{
		tr[u].mx = dp[l - 1];
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid, dp), build(u << 1 | 1, mid + 1, r, dp);
	pushup(u);
}

void rangeAdd(int u, int l, int r, int ql, int qr, int x)
{
	if(l >= ql && r <= qr)
	{
		apply_add(u, x);
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
	return rangeAdd(1, 1, n, ql, qr, x);
}

int max_query(int u, int l, int r, int ql, int qr)
{
	if(l >= ql && r <= qr) return tr[u].mx;

	pushdown(u);

	int mid = l + r >> 1;
	int res = -INF;
	if(ql <= mid) res = max(res, max_query(u << 1, l, mid, ql, qr));
	if(qr >= mid + 1) res = max(res, max_query(u << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

int max_query(int ql, int qr)
{
	return max_query(1, 1, n, ql, qr);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >>n >>k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	
	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	vector<int> pre(n + 1), last(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	for(int j = 1; j <= k; j ++)
	{
		build(1, 1, n, dp);
		vector<int> ndp(n + 1, -INF);

		for(int i = 1; i <= n; i ++)
		{
			int x = a[i];
			rangeAdd(pre[i] + 1, i, 1);
			if(i >= j) ndp[i] = max_query(j, i);
		}

		swap(dp, ndp);
	}
	cout <<dp[n] <<endl;
	return 0;
}
