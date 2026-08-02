#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;
		s = " " + s;
		vector<i64> match(n + 1, -1), a(n + 1), pre(n + 1);
		vector<int> stk;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
			
			char c = s[i];
			if(c == 'a') stk.push_back(i);
			else
			{
				if(stk.size())
				{
					match[i] = stk.back();
					stk.pop_back();
				}
			}
		}
		stk.assign(n + 1, 0);
		int len = 0;
		vector<i64> sum(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			if(match[i] == -1)
			{
				len ++;
				stk[len] = i;
				sum[len] = sum[len - 1] + a[i];
			}
			else
			{
				int l = match[i];
				int idx = lower_bound(stk.begin() + 1, stk.begin() + len + 1, l) - stk.begin();
				// cout <<"idx: " <<idx <<endl;
				// cout <<"l : " <<l <<endl;
				if(sum[len] - sum[idx - 1] + a[i] < 0) len = idx - 1;
				else
				{
					len ++;
					stk[len] = i;
					sum[len] = sum[len - 1] + a[i];
				}
			}
			// for(int j = 1; j <= len; j ++)
				// cout <<stk[j] <<" \n"[j == len];
		}
		i64 ans = 0;
		for(int i = 1; i <= len; i ++)
			ans += a[stk[i]];
		cout <<ans <<endl;
	}
	return 0;
}