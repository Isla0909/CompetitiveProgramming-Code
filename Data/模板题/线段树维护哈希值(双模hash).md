## 线段树维护哈希值(双模hash)

```c++
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int N = 5e5 + 10;
constexpr i64 P = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int n, m;
int a[N];

i64 p1[N], p2[N];
i64 inv1, inv2;

unordered_map<int, pair<int, int>> mp;

i64 qpow(i64 a, int b, i64 mod)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

pair<int, int> gethash(int x)
{
	if(x <= n) return {(int)p1[x], (int)p2[x]};

	if(mp.contains(x)) return mp[x];

	return mp[x] = {(int)qpow(P, x, mod1), (int)qpow(P, x, mod2)};
}

struct Info
{
	int mn, mx;
	i64 h1, h2;
};

Info operator+(const Info &a, const Info &b)
{
	Info c;
	c.mn = min(a.mn, b.mn);
	c.mx = max(a.mx, b.mx);
	c.h1 = (a.h1 + b.h1) % mod1, c.h2 = (a.h2 + b.h2) % mod2;
	return c;
}

Info tr[N << 2];

void pushup(int u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void build(int u, int l, int r)
{
	if(l == r)
	{
		auto [x, y] = gethash(a[l]);
		tr[u].mn = tr[u].mx = a[l];
		tr[u].h1 = x, tr[u].h2 = y;
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
		auto [h1, h2] = gethash(x);
		tr[u].mn = tr[u].mx = x;
		tr[u].h1 = h1, tr[u].h2 = h2;
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

	cin >>n >>m;
	for(int i = 1; i <= n; i ++) cin >>a[i];

	p1[0] = p2[0] = 1;
	for(int i =1 ; i <= n; i ++)
	{
		p1[i] = p1[i - 1] * P % mod1;
		p2[i] = p2[i - 1] * P % mod2;
	}

	inv1 = qpow(P - 1, mod1 - 2, mod1), inv2 = qpow(P - 1, mod2 - 2, mod2);
	mp.reserve(2 * n);

	build(1, 1, n);

	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int pos, x; cin >>pos >>x;
			modify(1, 1, n, pos, x);
		}
		else
		{
			int l, r; cin >>l >>r;

			Info res = query(1, 1, n, l, r);
			int len = r - l + 1;
			if(res.mx - res.mn + 1 != len)
			{
				cout <<"yuanxing" <<endl;
				continue;
			}

			auto [pm1, pm2] = gethash(res.mn);
			i64 v1 = pm1 * ((p1[len] - 1 + mod1) % mod1) % mod1 * inv1 % mod1;
			i64 v2 = pm2 * ((p2[len] - 1 + mod2) % mod2) % mod2 * inv2 % mod2;

			if(res.h1 == v1 && res.h2 == v2) cout <<"damushen" <<endl;
			else cout <<"yuanxing" <<endl;
		}
	}

	return 0;
}
```

