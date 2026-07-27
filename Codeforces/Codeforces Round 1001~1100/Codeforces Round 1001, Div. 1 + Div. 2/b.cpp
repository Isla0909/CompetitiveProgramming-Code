#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define st begin()
#define ed end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5 + 10;
int a[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			int res1 = 2 * (n - i);
			int res2 = 2 * (i - 1);
			a[i] -= max(res1, res2);
			//cout <<res1 <<" ";
			if(a[i] <= 0)
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