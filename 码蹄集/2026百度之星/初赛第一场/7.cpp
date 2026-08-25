#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	int sum = 0;
	vector<int> a(n + 1);
	int M = 0, cnt = 0, bad = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		if(a[i] != -1) sum += a[i];
		else bad ++;

		if(a[i] > M)
		{
			M = a[i];
			cnt = 1;
		}
		else if(a[i] == M) cnt ++;
	}

	// if(cnt > 1) M ++; 
	//cout <<sum <<" " <<M <<" " <<bad <<endl;
	vector<int> ans;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] != -1)
		{
			if(a[i] < M || a[i] == M && cnt != 1) continue;
			if(!bad)
			{
				if(a[i] == M) ans.push_back(i);
				continue;
			}
			if(a[i] > (n - sum + bad - 1) / bad) ans.push_back(i);
		}
		else
		{
			if(n - sum > M) ans.push_back(i);
		}
	}
	tell(0, ans);
	return 0;
}