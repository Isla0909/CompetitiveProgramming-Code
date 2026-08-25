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

	int x, y; cin >>x >>y;
	cout <<100 - x - y <<endl;
	return 0;
}