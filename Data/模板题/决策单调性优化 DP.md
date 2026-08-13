## **决策单调性优化 DP**

给定一个序列 $a$，要把它分成 $k$ ($k <= 20$) 个子段。每个子段的费用是其中相同元素的对数。求所有子段的费用之和的最小值。

```c++
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
constexpr long long inf = 1e18;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, k;
int a[N], cnt[N];

int l = 1, r = 0;
i64 res = 0;

i64 pre[N], f[N];

void add(int x)
{
	res += cnt[x];
	cnt[x] ++;
}

void del(int x)
{
	cnt[x] --;
	res -= cnt[x];
}

i64 get(int ql, int qr)
{
	while(l > ql) add(a[-- l]);
	while(r < qr) add(a[++ r]);
	while(l < ql) del(a[l ++]);
	while(r > qr) del(a[r --]);
	return res; 
}

void solve(int l, int r, int ql, int qr)
{
	if(l > r) return ;

	int mid = l + r >> 1;
	f[mid] = inf;

	int ed = min(mid - 1, qr), pos = -1;
	for(int j = ql; j <= ed; j ++)
	{
		i64 v = pre[j] + get(j + 1, mid);
		if(v < f[mid])
		{
			f[mid] = v;
			pos = j;
		}
	}
	solve(l, mid - 1, ql, pos), solve(mid + 1, r, pos, qr);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	for(int i = 1; i <= n; i ++) cin >>a[i];

	fill(pre, pre + n + 1, inf);
	pre[0] = 0;

	for(int t = 1; t <= k; t ++)
	{
		fill(f, f + n + 1, inf);

		solve(t, n, t - 1, n - 1);

		for(int i = 0; i <= n; i ++)
			pre[i] = f[i];
	}
	cout <<pre[n] <<endl;
	return 0;
}

```

