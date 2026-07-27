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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int a[N], cnt[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		memset(cnt, 0, sizeof cnt);
		
		int n; cin >>n;
		for(int i = 1; i <= n; i ++)
		{
		    cin >>a[i];
		    cnt[a[i]] ++;
		}
		
		if(n == 1)
        {
           cout <<"1 1" <<endl;
            continue;
        }
		
		
		int ans = 0, l = -1, r;
		for(int i = 1; i <= n; i ++)
		{
		    if(cnt[a[i]] == 1)
		    {
		        int j;
		        for(j = i; j < n; j ++)
		        {
		            if(j + 1 <= n && cnt[a[j + 1]] > 1) break;
		        }
		        if(j - i + 1 > ans)
		        {
		            l = i, r = j;
		            ans = j - i + 1;
		        }
		        i = j;
		    }
		}
		if(l == -1) cout <<0 <<endl;
		else cout <<l <<" " <<r <<endl;
	}
	return 0;
}