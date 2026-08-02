#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		i64 n; cin >>n;
		if(n <= 2) cout <<0 <<endl;
		else
		{
			if(n & 1)
			{
				i64 k = n / 2;
				i64 ans = n * k;
				if(n % 3 == 0)
				{
					i64 c = n / 3;
					ans -= c * 2;
				}
				cout <<ans <<endl;
			}
			else
			{
				i64 k = n / 2 - 1;
				i64 ans = n * k;
				if(n % 3 == 0)
				{
					i64 c = n / 3;
					ans -= c * 2;
				}
				cout <<ans <<endl;
			}
		}
	}
	return 0;
}