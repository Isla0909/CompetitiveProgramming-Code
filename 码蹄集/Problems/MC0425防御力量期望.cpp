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

constexpr int N = 105, INF = 0x3f3f3f3f, mod = 998244353;

i64 quick_pow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1LL) res = res * a % mod;

		a = a * a % mod;
		b >>= 1LL;
	}
	return res;
}

i64 inv(i64 x)
{
	return quick_pow(x, mod - 2);
}

i64 C[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	C[0][0] = 1;
	for(int i = 1; i < N; i ++)
		for(int j = 0; j <= i; j ++)
		{
			if(!j) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}

	int n, m; cin >>n >>m;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	i64 p = inv(n), q = (1 + mod - p) % mod;

	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		i64 c = a[i];
		for(int j = 0; j <= m; j ++, c /= 2LL)
		{
			ans = (ans + C[m][j] * quick_pow(p, j) % mod * quick_pow(q, m - j) % mod * c % mod) % mod;
		}
	}
	cout <<ans <<endl;
	return 0;
}
