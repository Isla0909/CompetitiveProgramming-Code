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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

i64 qpow(i64 a, i64 b)
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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<i64> invf(n + 1);
	invf[0] = 1;
	for(int i = 1; i <= n; i ++)
		invf[i] = invf[i - 1] * qpow(i, mod - 2) % mod;
	
	vector<i64> dp(n + 1);
	dp[1] = 1;
	for(int i = 2; i <= n; i ++)
	{
		int k = i + 1 >> 1;
		dp[i] = (dp[k] + (i - k) * invf[i] % mod) % mod;
	}
	cout <<dp[n] <<endl;
	return 0;
}
