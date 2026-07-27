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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int h[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 1; i <= n; i ++) cin >>h[i];


	vector <int> dp(n + 1, INF);

	dp[1] = 0;
	for(int i = 2; i <= n; i ++)
	{
		dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
		dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
	}
	cout <<dp[n] <<endl;
	return 0;
}