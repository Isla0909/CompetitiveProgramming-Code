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

constexpr int N = 5e5 + 10, P = 131, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

void build(int u, int l, int r)
{
	tr[u] = {};
	tr[u].len = r - l + 1;

	if(l == r) return;

	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int pos)
{
	if(l == r)
	{
		tr[u].h = tr[u].rh = 1;
		return ;
 	}

	int mid = l + r >> 1;
	if(pos <= mid) modify(u << 1, l, mid, pos);
	else modify(u << 1 | 1, mid + 1, r, pos);

	tr[u] = tr[u << 1] + tr[u << 1 | 1];
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
		p[i] = p[i - 1] * P;

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >>a[i];

		build(1, 1, n);

		bool f = false;
		for(int i = 1; i <= n; i ++)
		{
			int x = a[i];
			int len = min(x - 1, n - x);

			if(len)
			{
				Info L = query(1, 1, n, x - len, x - 1);
				Info R = query(1, 1, n, x + 1, x + len);

				if(L.rh != R.h)
				{
					f = true;
					break;
				}
			}
			modify(1, 1, n, x);
		}
		cout <<(f ? "Y" : "N") <<endl;
	}
	return 0;
}
