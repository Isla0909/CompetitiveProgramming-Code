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
int cnt[N];


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
			int x; cin >>x;
			cnt[x] ++;
		}
		bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(cnt[i] == 1)
			{
				f = 0;
				break;
			}
			else if(cnt[i] >= 2)
			{
				cnt[i + 1] += cnt[i] - 2;
			}
		}
		if(cnt[n + 1] & 1) f = 0;
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}