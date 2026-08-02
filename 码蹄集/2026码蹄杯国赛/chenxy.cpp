#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >>s;
	auto check = [&](char a, char b) -> bool
	{
		for(auto c : s)
			if(c < a || c > b) return false;
		return true;
	};
	if(check('A', 'Z') || check('a', 'z')) cout <<"Yes" <<endl;
	else cout <<"No" <<endl;
	return 0;
}