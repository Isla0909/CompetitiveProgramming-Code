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
int a[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		for(int i = 2; i <= n; i ++)
		{
			if(i + 1 <= n)
			{
				int x = min(a[i], a[i - 1]);
				a[i] -= x, a[i - 1] -= x;
			}
		}
		bool f = 1;
		for(int i = 2; i <= n; i ++)
		{
			if(a[i] < a[i - 1])
			{
				f = 0;
				break;
			}
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}