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
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int a[N], s1[N], s2[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];
	
	    for(int i = 1; i <= n; i ++)
	    {
	        if(a[i] >= 0) s1[i] = s1[i - 1] + a[i], s2[i] = s2[i - 1];
	        else s2[i] = s2[i - 1] - a[i], s1[i] = s1[i - 1];
	    }
	    
	    int ans = -1;
	    for(int i = 0; i <= n; i ++)
	    {
	        int x = s1[i] + s2[n] - s2[i];
	        ans = max(ans, x);
	    }
		cout <<ans <<endl;
	}
	return 0;
}