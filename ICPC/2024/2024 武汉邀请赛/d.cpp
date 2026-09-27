#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<i64> pre(n + 1), res(n + 1);
	vector<i64> dp(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		pre[i] = pre[i - 1] + x;
		dp[i] = x;
	}

	for(int t = 1; t <= 2 * n; t ++)
	{
		auto ndp = dp;
		for(int i = 1; i <= n; i ++)
		{
			int l = max(1, i - t), r = min(n, i + t);

			i64 v = max(pre[i] - pre[l - 1], pre[r] - pre[i - 1]);
			if(i - 1 >= 1) v = max(v, dp[i - 1]);
			if(i + 1 <= n) v = max(v, dp[i + 1]);

			ndp[i] = v;
			res[i] ^= v * t;
		}
		dp.swap(ndp);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
		ans ^= res[i] + i;
	cout <<ans <<endl;
	return 0;
}