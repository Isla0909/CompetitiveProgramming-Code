#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define st begin()
#define ed end()
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int a[N], b[N], c[N], d[N];

int quick_pow(int a, int b, int q)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % q;
		a = a * a % q;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			c[i] = a[i];
		}
		for(int i = 1; i <= n; i ++)
		{
			cin >>b[i];
			d[i] = b[i];
		}
		sort(c + 1, c + 1 + n), sort(d + 1, d + 1 + n);
		int res = 1;
		for(int i = 1; i <= n; i ++)
			res = res * min(c[i], d[i]) % mod;
		cout <<res <<" ";
		while(q --)
		{
			int op, x; cin >>op >>x;
			if(op == 1)
			{
				int v = a[x];
				int idx = upper_bound(c + 1, c + 1 + n, v) - (c + 1);
				res = res * quick_pow(min(c[idx], d[idx]), mod - 2, mod), res %= mod;
				res *= min(v + 1, d[idx]), res %= mod;
				a[x] ++, c[idx] ++;
			}
			else
			{
				int v = b[x];
				int idx = upper_bound(d + 1, d + 1 + n, v) - (d + 1);
				res = res * quick_pow(min(c[idx], d[idx]), mod - 2, mod), res %= mod;
				res *= min(c[idx] , v + 1), res %= mod;
				b[x] ++, d[idx] ++;
			}
			cout <<res <<" ";
		}
		cout <<endl;
	}
	return 0;
}