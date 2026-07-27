#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int count1(int x)
{
	return __builtin_popcount(x);
}

int quick_pow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % mod;

		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return res;
}

int fac[N], inv[N];

void initial()
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i < N; i ++)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[i - 1] * quick_pow(i, mod - 2) % mod;
	}
}

int C(int n, int m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	initial();

	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector f(n + 1, vector<i64>(m + 1));
	for(int j = 0; j <= m; j ++)
	{
		int c = a[1] + j;
		f[1][j] = count1(c);
	}

	for(int i = 2; i <= n; i ++)
	{
		for(int j = 0; j <= m; j ++)
		{
			for(int k = 0; k <= j; k ++)
			{
				int c = a[i] + k;
				f[i][j] = (f[i][j] + C(j, k) * (f[i - 1][j - k] + count1(c)) % mod) % mod;
			}
		}
	}

	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= m; j ++)
			cout <<f[i][j] <<" \n"[j == m];

	cout <<f[n][m] <<endl;
	return 0;
}