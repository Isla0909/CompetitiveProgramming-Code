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

const int N = 1e3 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
char g[N][N];
int dp[N][N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];
	dp[1][1] = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(g[i][j] == '.')
			{
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
	cout <<dp[n][m] <<endl;
	return 0;
}