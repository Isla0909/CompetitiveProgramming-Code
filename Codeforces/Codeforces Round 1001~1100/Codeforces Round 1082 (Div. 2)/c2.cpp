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
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> stk; 
		vector<int> l(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x = a[i];
			if(stk.empty()) 
			{
				stk.push_back(i);
				l[i] = 0;
			}
			else if(x == a[stk.back()] + 1)
			{
				l[i] = stk.back();
				stk.push_back(i);
			}
			else
			{
				while(stk.size() && a[stk.back()] != x - 1) stk.pop_back();
				if(stk.empty()) l[i] = 0;
				else l[i] = stk.back();
				stk.push_back(i);
			}
		}
      	i64 ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			int L = i - l[i], R = n - i + 1;
			ans += 1LL * L * R;
		}
		cout <<ans <<endl;
	}
	return 0;
}
