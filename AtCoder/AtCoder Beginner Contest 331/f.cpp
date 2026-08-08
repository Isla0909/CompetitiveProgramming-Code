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

int a[N];
u64 p[N];

struct Info
{
	u64 h, rh;
	int len = 0;
};

Info operator+(const Info &a, const Info &b)
{
	Info c;
	c.len = a.len + b.len;
	c.h = a.h * p[b.len] + b.h;
	c.rh = b.rh * p[a.len] + a.rh;
	return c;
}

Info tr[N << 2];

void pushup(int u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void build(int u, int l, int r)
{
	tr[u].len = r - l + 1;

	if(l == r)
	{
		tr[u].h = tr[u].rh = a[l];
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
		tr[u].h = tr[u].rh = x;
		return ;
 	}

	int mid = l + r >> 1;
	if(pos <= mid) modify(u << 1, l, mid, pos, x);
	else modify(u << 1 | 1, mid + 1, r, pos, x);

	pushup(u);
}

Info query(int u, int l, int r, int ql, int qr)
{
	if(l >= ql && r <= qr) return tr[u];

	int mid = l + r >> 1;

	if(qr <= mid) return query(u << 1, l, mid, ql, qr);
	if(ql >= mid + 1) return query(u << 1 | 1, mid + 1, r, ql, qr);
	return query(u << 1, l, mid, ql, qr) + query(u << 1 | 1, mid + 1, r, ql, qr);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < N; i ++)
		p[i] = p[i - 1] * 131;

	int n, q; cin >>n >>q;
	string s; cin >>s;
	for(int i = 1; i <= n; i ++)
		a[i] = s[i - 1] - 'a' + 1;

	build(1, 1, n);
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int pos; char c;
			cin >>pos >>c;
			int x = c - 'a' + 1;
			modify(1, 1, n, pos, x);
		}
		else
		{
			int l, r; cin >>l >>r;
			cout <<(query(1, 1, n, l, r).h == query(1, 1, n, l, r).rh ? "Yes" : "No") <<endl;
		}
	}
	return 0;
}
