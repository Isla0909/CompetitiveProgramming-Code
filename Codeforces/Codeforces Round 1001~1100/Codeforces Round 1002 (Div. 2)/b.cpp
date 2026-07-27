#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;

		int a[n + 1];
		for(int i = 1; i <= n; i ++) cin >>a[i];

		if(n == k)
		{
		    int idx = 1;
		    for(int i = 2; i <= n; i += 2)
		    {
		        if(a[i] != idx) break;
		        idx ++;
		    }
		    cout <<idx <<endl;
		    continue;
		}
		else
		{
		    int l = n - k; bool f = 1;
		    for(int i = 2; i <= l + 2; i ++)
		    {
		        if(a[i] != 1)
		        {
		            f = 0;
		            break;
		        }
		    }
		    if(f) cout <<2 <<endl;
		    else cout <<1 <<endl;
		}
	}
	return 0;
}