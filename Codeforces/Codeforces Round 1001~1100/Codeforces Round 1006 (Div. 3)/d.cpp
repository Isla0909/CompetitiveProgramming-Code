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

const int N = 2e3 + 10, INF = 0x3f3f3f3f;


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector <int> a(n + 1, 0);
		vector <vector<int>> g(n + 1, vector <int> (n + 1, 0));
		vector <vector<int>> h(n + 1, vector <int> (n + 1, 0));

		
		for(int i = 1; i <= n; i ++) cin >>a[i];

		for(int i = 1; i <= n; i ++)
		{
			int x = a[i]; int s = 0, u = 0;
			for(int j = i + 1; j <= n; j ++)
			{
				if(a[j] > x) s ++;
				if(a[j] < x) u ++;
				g[i][j] = s, h[i][j] = u;
			}
		}
		int ans = -1, l = 1, r = 1;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i; j <= n; j ++)
			{
				if(h[i][j] - g[i][j] > ans)
				{
					ans = h[i][j] - g[i][j];
					l = i, r = j;
				}
				
			}
		}
		cout <<l <<" " <<r <<endl;
	}
	return 0;
}