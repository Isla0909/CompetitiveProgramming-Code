#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3, mod = 998244353;
int a[N];
int dp[N][2];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		if(a[1] == 0) dp[1][1] = dp[1][0] = 1;
		else dp[1][1] = 0, dp[1][0] = 1;
		dp[0][1] = 1;
		for(int i = 2; i <= n; i ++)
		{
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = 0;
			if(a[i] == a[i - 1])
			{
				dp[i][1] += dp[i - 1][1];
				dp[i][1] %= mod;
			}
			if(a[i] == a[i - 2] + 1)
			{
				dp[i][1] += dp[i - 2][1];
				dp[i][1] %= mod;
			}
		}
		cout <<(dp[n][0] + dp[n][1]) % mod <<endl;
	}
	return 0;
}