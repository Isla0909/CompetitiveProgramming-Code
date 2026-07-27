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
#define st begin()
#define ed end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 700 + 10, INF = 0x3f3f3f3f;
int g[N][N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		map <int, int> mp;

		int n, m; cin >>n >>m;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];
		
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				int x = g[i][j];
				if(mp[x]) continue;
				int cnt = 0;
				if(i - 1 >= 1 && g[i][j] == g[i - 1][j]) cnt ++;
				if(j - 1 >= 1 && g[i][j] == g[i][j - 1]) cnt ++;
				if(cnt) mp[x] = 1;
				else mp[x] = 0;
			}
		}
		int s1 = 0, s2 = 0;
		for(auto x : mp)
		{
			if(x.se) s2 ++;
			else s1 ++;
		}
		if(s2) cout <<2 * (s2 - 1) + s1 <<endl;
		else cout <<s1 - 1 <<endl;
	}
	return 0;
}