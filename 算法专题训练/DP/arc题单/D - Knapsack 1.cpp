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
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int w[N], v[N];
int dp[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	for(int i = 1; i <= n; i ++) cin >>v[i] >>w[i];

	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= v[i]; j --)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	}
	cout <<dp[m] <<endl;
	return 0;
}