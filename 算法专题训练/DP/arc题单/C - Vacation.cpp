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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int a[N], b[N], c[N];
int dp[N][4];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 1; i <= n; i ++) cin >>a[i] >>b[i] >>c[i];

	for(int i = 1; i <= n; i ++)
	{
		dp[i][1] = max(dp[i - 1][2] + a[i], dp[i - 1][3] + a[i]);
		dp[i][2] = max(dp[i - 1][1] + b[i], dp[i - 1][3] + b[i]);
		dp[i][3] = max(dp[i - 1][1] + c[i], dp[i - 1][2] + c[i]);
	}

	cout <<max(dp[n][1], max(dp[n][2], dp[n][3])) <<endl;
	return 0;
}