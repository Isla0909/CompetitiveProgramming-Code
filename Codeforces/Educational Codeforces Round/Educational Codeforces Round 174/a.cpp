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
int a[N], b[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n - 2; i ++) cin >>a[i];
		    
		bool f = 1;
		for(int i = 1; i <= n - 2; i ++)
		    if(i - 1 >= 1 && i + 1 <= n - 2 && a[i] == 0 && a[i - 1] && a[i + 1]) 
		    	f = 0;
        if(f) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
	}
	return 0;
}