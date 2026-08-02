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
		int n, x; cin >>n >>x;
		vector<int> v;
		for(int i = x; i <= n; i ++)
			v.push_back(i);
		for(int i = 1; i <= x / 2; i ++)
			v.push_back(i);
		cout <<v.size() <<endl;
		tell(0, v);
	}
	return 0;
}