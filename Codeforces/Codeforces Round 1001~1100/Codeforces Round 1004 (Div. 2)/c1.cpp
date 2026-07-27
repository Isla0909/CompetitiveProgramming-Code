#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

bool check(ll x)
{
	char s[20];
	sprintf(s,"%lld", x);
	bool f = 0;
	for(int i = 0; s[i]; i ++)
		if(s[i] == '7')
		{
			f = 1;
			break;
		}
	return f;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		ll n; cin >>n;
		
		if(check(n))
		{
			cout <<0 <<endl;
			continue;
		}

		int ans = INF;
		for(int i = 1; i <= 10; i ++)
		{	
			ll t = i, x = 0;
			while(t --) x = x * 10 + 9;
			for(int j = 1; j <= min(ans, 11); j ++)
			{
				ll p = n + (ll) x * j;
				if(check(p))
				{
					ans = min(ans, j);
					//cout <<x <<" " <<p  <<" " <<j <<endl;
				}
			}
		}
		cout <<ans <<endl;;
	}
	return 0;
}