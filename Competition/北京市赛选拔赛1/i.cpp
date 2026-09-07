#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int MOD = 998244353;
constexpr int G = 3;

int qpow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void ntt(vector<int> &a, bool invert)
{
	int n = a.size();
	for(int i = 1, j = 0; i < n; i ++)
	{
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}

	for(int len = 2; len <= n; len <<= 1)
	{
		int wlen = qpow(G, (MOD - 1) / len);
		if(invert) wlen = qpow(wlen, MOD - 2);

		for(int i = 0; i < n; i += len)
		{
			int w = 1;
			for(int j = 0; j < len / 2; j ++)
			{
				int u = a[i + j];
				int v = 1LL * a[i + j + len / 2] * w % MOD;
				a[i + j] = u + v;
				if(a[i + j] >= MOD) a[i + j] -= MOD;
				a[i + j + len / 2] = u - v;
				if(a[i + j + len / 2] < 0) a[i + j + len / 2] += MOD;
				w = 1LL * w * wlen % MOD;
			}
		}
	}

	if(invert)
	{
		int inv_n = qpow(n, MOD - 2);
		for(int &x : a) x = 1LL * x * inv_n % MOD;
	}
}

vector<i64> convolution(const vector<i64> &a, const vector<i64> &b)
{
	if(a.empty() || b.empty()) return {};
	int need = a.size() + b.size() - 1;
	int n = 1;
	while(n < need) n <<= 1;
	assert(n <= (1 << 23));

	vector<int> fa(n), fb(n);
	for(int i = 0; i < (int)a.size(); i ++)
		fa[i] = (a[i] % MOD + MOD) % MOD;
	for(int i = 0; i < (int)b.size(); i ++)
		fb[i] = (b[i] % MOD + MOD) % MOD;

	ntt(fa, false);
	ntt(fb, false);
	for(int i = 0; i < n; i ++) fa[i] = 1LL * fa[i] * fb[i] % MOD;
	ntt(fa, true);

	vector<i64> c(need);
	for(int i = 0; i < need; i ++) c[i] = fa[i];
	return c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	return 0;
}