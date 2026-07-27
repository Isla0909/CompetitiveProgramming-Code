#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 400 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int dp[N][N];
int a[N], s[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	memset(dp, 0x3f, sizeof dp);

	int n; cin >>n;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		s[i] = s[i - 1] + a[i];
	}

	for(int len = 1; len <= n; len ++)
	{
		for(int i = 1; i + len - 1 <= n; i ++)
		{
			int l = i, r = i + len - 1;
			if(l == r)
			{
				dp[l][r] = 0;
				continue;
			}
			for(int k = l; k <= r; k ++)
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
		}
	}
	cout <<dp[1][n] <<endl;
	return 0;
}