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
int a[N], b[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		int cnt = 0; int m = INF; int x = 0;
		for(int i = 1; i <= n; i ++)
		{
			a[i] = a[i] - b[i];
			if(a[i] < 0)
			{
				x = a[i];
				cnt ++;
			}
			else m = min(m, a[i]);
		}
		if(cnt > 1) cout <<"NO" <<endl;
		else
		{
			if(x + m >= 0) cout <<"YES" <<endl;
			else cout <<"NO" <<endl;
		}
	}
	return 0;
}