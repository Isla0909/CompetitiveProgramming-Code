#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{	
	int T = 0;
	while(1)
	{
		cout <<"Test " <<T ++ <<" ";
		system("data.exe > data.in");
		system("WA.exe < data.in > WA.out");
		system("AC.exe < data.in > AC.out");
		
		if(system("fc AC.out WA.out > diff.log"))
		{
			cout <<"Wrong Answer" <<endl;
			system("type data.in");
			cout <<"---------------------------" <<endl;
			system("type AC.out");
			cout <<"---------------------------" <<endl;
			system("type WA.out");
			break;
		}
		cout <<"Accepted" <<endl;
	}
	return 0; 	
} 
