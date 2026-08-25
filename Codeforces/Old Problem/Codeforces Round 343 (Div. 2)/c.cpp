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

constexpr int N = 2e3 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dp[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	string s; cin >>s;

	if(n & 1)
	{
		cout <<0 <<endl;
		return 0;
	}

	int k = n - m;

	dp[0][0] = 1;
	for(int i = 1; i <= k; i ++)
		for(int j = 0; j <= i; j ++)
		{
			//'('
			if(j >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;

			if(j + 1 <= i - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
		}

	int sum = 0, mn = 0;
	for(auto c : s)
	{
		if(c == '(') sum ++;
		else sum --;

		mn = min(mn, sum);
	}

	i64 ans = 0;
	for(int len = 0; len <= k; len ++)
	{
		int r = k - len;
		for(int j = 0; j <= len; j ++)
		{
			if(!dp[len][j] || j + mn < 0) continue;

			int balance = j + sum;
			if(balance > r) continue;

			ans = (ans + 1LL * dp[len][j] * dp[r][balance]) % mod;
		}
	}
	cout <<ans <<endl;
	return 0;
}
