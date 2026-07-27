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

constexpr int N = 3000 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

i64 quick_pow(i64 a, i64 b)
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

i64 inv(i64 x)
{
	return quick_pow(x, mod - 2);
}

i64 fac[N], invf[N];

i64 C(int n, int m)
{
	return fac[n] * invf[m] % mod * invf[n - m] % mod;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fac[0] = invf[0] = 1;
	for(int i = 1; i < N; i ++)
	{
		fac[i] = fac[i - 1] * i % mod;
		invf[i] = invf[i - 1] * inv(i) % mod;
	}

	int T; cin >>T;
	while(T --)
	{
		int n, x; cin >>n >>x;
		i64 sum = 0;
		vector<i64> v;
		for(int i = 0; i < n; i ++)
		{
			string s; cin >>s;
			char c = s[0];
			i64 y = stoll(s.substr(1));

			if(c == '+') sum = (sum + y) % mod;
			else if(c == '-') sum = (sum + mod - y) % mod;
			else if(c == 'x') v.push_back(y);
			else v.push_back(inv(y));
		}

		i64 M = 1;
		for(auto y : v)
			M = M * y % mod;

		int m = v.size();
		vector f(m + 1, vector<i64>(m + 1));
		f[0][0] = 1;
		for(int i = 1; i <= m; i ++)
		{
			i64 y = v[i - 1];
			f[i][0] = 1;
			for(int j = 1; j <= i; j ++)
			{
				f[i][j] = f[i - 1][j];
				f[i][j] = (f[i][j] + f[i - 1][j - 1] * y) % mod;
			}
		}

		i64 S = 0;
		for(int i = 0; i <= m; i ++)
		{
			S += inv(C(m, i)) * f[m][i];
			S %= mod;
		}
		S *= inv(m + 1);
		S %= mod;
		cout <<(x * M % mod + sum * S % mod) % mod <<endl; 
	}
	return 0;
}
