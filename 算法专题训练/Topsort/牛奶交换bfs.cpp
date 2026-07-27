#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	int sum = 0;
	string s; cin >>s;
	vector <int> a(n), din(n), cnt(n);
	for(int i = 0; i < n; i ++)
	{
		cin >>a[i], sum += a[i];
		cnt[i] = a[i];
	}

	for(int i = 0; i < n; i ++)
	{
		if(s[i] == 'L') din[(i - 1 + n) % n] ++;
		else din[(i + 1 + n) % n] ++;
	}

	queue <int> q;
	for(int i = 0; i < n; i ++)
		if(!din[i]) q.push(i);

	int add = 0;
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int nex = (s[t] == 'L') ? (t - 1 + n) % n : (t + 1) % n;

		cnt[nex] += cnt[t];
		din[nex] --;
		if(cnt[t] < m && !din[nex]) q.push(nex);
		else if(cnt[t] >= m) add += m;
		else if(din[nex]) add += cnt[t];
	}
	cout <<sum - add <<endl;
	return 0;
}