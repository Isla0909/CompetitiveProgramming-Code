#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 310, INF = 0x3f3f3f3f;
int n; 
int g[N][N];
int cnt[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		memset(cnt, 0, sizeof cnt);

		cin >>n;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				cin >>g[i][j];

		for(int i = 1; i <= n; i ++)
		{
		    int l = 0;
		    for(int j = n; j >= 1; j --)
		    {
		        if(g[i][j] == 1) l ++;
		        else break;
		    }
		    cnt[l] ++;
		}
		
		if(n == 1)
		{
		    cout <<1 <<endl;
		    continue;
		}
		
		for(int i = 0; i <= n; i ++)
		{
		    if(!cnt[i])
		    {
		        bool f = 0;
		        for(int j = i + 1; j <= n; j ++)
		        {
		            if(cnt[j])
		            {
		                cnt[j] --;
		                f = 1;
		                break;
		            }
		        }
		        if(!f)
		        {
		             cout <<i <<endl;
		             break;
		        }
		    }
		}
	}
	return 0;
}