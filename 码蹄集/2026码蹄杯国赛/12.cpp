#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	int ans = 0;
	for(int i = k; i <= n; i += k)
		ans += a[i];
	cout <<ans <<endl;
	return 0;
}