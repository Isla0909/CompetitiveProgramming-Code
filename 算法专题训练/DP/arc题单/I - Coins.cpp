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
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e3 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
double p[N];
double dp[N][N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	//cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 1; i <= n; i ++) cin >>p[i];

	dp[1][1] = p[1], dp[1][0] = 1 - p[1];
	for(int i = 2; i <= n; i ++)
	{
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);
		for(int j = 1; j <= i; j ++)
		{
			dp[i][j] += p[i] * dp[i - 1][j - 1];
			dp[i][j] += (1 - p[i]) * dp[i - 1][j];
		}
	}
	double ans = 0;
	for(int i = n; i > n / 2; i --)
		ans += dp[n][i];
	printf("%.10lf\n", ans);
	return 0;
}