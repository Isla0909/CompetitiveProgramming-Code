#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using i64 = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a = rng() % 40, b = rng() % 40;
	cout <<a <<" " <<b <<endl;
	
	return 0; 	
} 
