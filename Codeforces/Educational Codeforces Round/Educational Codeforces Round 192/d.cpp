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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		string a, b; cin >>a >>b;
		int n = a.size(), m = b.size();
		a = " " + a, b = " " + b;

		vector<int> pre1(n + 1), pre2(m + 1);
		for(int i = 1; i <= n; i ++)
			pre1[i] = (pre1[i - 1] + a[i] - '0') % 10;
		for(int i = 1; i <= m; i ++)
			pre2[i] = (pre2[i - 1] + b[i] - '0') % 10;

		vector<array<int, 10>> dp(m + 1), ndp(m + 1);
		for(int i = 0; i <= m; i ++)
			for(int j = 0; j < 10; j ++)
				dp[i][j] = ndp[i][j] = -INF;
		dp[0][0] = 0;

		for(int j = 1; j <= m; j ++)
			dp[j] = dp[j - 1];
		
		int ans = -INF;
		for(int i = 1; i <= n; i ++)
		{
			ndp[0] = dp[0];
			for(int j = 1; j <= m; j ++)
			{
				int x = (pre1[i] - pre2[j] + 10) % 10;

				int v = -INF;
				if(dp[j - 1][x] != -INF) v = dp[j - 1][x] + 1;

				for(int k = 0; k < 10; k ++)
					ndp[j][k] = max(dp[j][k], ndp[j - 1][k]);

				if(v != -INF) ndp[j][x] = max(ndp[j][x], v); 

				if(i == n && j == m) ans = v;
			}
			swap(dp, ndp);
		}
		cout <<(ans == -INF ? -1 : ans) <<endl;

		// vector dp(n + 1, vector<int>(m + 1, -INF));
		// dp[0][0] = 0;
		// for(int i = 1; i <= n; i ++)
		// 	for(int j = 1; j <= m; j ++)
		// 		for(int p = 1; p <= i; p ++)
		// 			for(int q = 1; q <= j; q ++)
		// 			{
		// 				if(dp[p - 1][q - 1] == -INF) continue;

		// 				if((pre1[i] - pre1[p - 1] + 10) % 10 == (pre2[j] - pre2[q - 1] + 10) % 10)
		// 					dp[i][j] = max(dp[i][j], dp[p - 1][q - 1] + 1);
		// 			}
		

		// cout <<(dp[n][m] == -INF ? -1 : dp[n][m]) <<endl;
	}
	return 0;
}
