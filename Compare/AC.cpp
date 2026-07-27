#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b; cin >>a >>b;
	int sum = 0;
	for(int i = 1; i <= a; i ++) sum ++;
	for(int i = 1; i <= b; i ++) sum ++;
	cout <<sum <<endl;
	return 0; 	
} 
