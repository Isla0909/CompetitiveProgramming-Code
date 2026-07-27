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
int w[110], v[110];
int dp[N];

void tell(int w[], int n)
{
	for(int i = 0; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	for(int i = 1; i <= n; i ++) cin >>v[i] >>w[i];

	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = N - 1; j >= w[i]; j --)
			dp[j] = min(dp[j], dp[j - w[i]] + v[i]);


		//tell(dp, 10);
	}
	
	for(int j = N - 1; j >= 0; j --)
		if(dp[j] <= m)
		{
			cout <<j <<endl;
			break;
		}

	return 0;
}