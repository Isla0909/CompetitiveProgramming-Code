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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

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

i64 inv(int x)
{
	return quick_pow(x, mod - 2);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	vector<i64> p(101);
	for(int i = 1; i <= 100; i ++)
		p[i] = inv(i) / inv(100); 

	vector f(n + 1, vector<i64>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(g[i][j] == '1') f[i][j] = 1;

	int q; cin >>q;
	while(q --)
	{
		int i, j, l, r, x; cin >>i >>j >>l >>r >>x;
		if(!x) continue;

		// for(int u = l; u <= r; u ++)
		// {
		// 	int a = g[i][u] - '0', b = g[j][u] - '0';
		// 	if(!a && b) f[j][u] = (f[j][u] * p[100 - x]) % mod;
		// }
	}
	vector<i64> col(m + 1, 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			col[j] = (col[j] * f[i][j]) % mod;
	i64 ans = 0;
	for(int j = 1; j <= m; j ++)
		ans += col[j];
	cout <<ans <<endl;
	return 0;
}
