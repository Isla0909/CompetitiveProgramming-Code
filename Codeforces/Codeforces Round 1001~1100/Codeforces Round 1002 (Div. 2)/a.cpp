#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

map <int, bool> mp1;
map <int, bool> mp2;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		mp1.clear(), mp2.clear();

		int n; cin >>n;
		int a[n], b[n];
		int s1 = 0, s2 = 0;
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			if(!mp1[x])
			{
				s1 ++;
				mp1[x] = 1;
			}
		}
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			if(!mp2[x])
			{
				s2 ++;
				mp2[x] = 1;
			}
		}
		if(s1 + s2 > 3) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}