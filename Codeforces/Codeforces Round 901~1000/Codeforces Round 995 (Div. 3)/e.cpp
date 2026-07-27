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
int n, k; int ans = -1;
int a[N], b[N];

void check(int x)
{
	int good = n - (lower_bound(a + 1, a + 1 + n, x) - (a + 1));
	int all = n - (lower_bound(b + 1, b + 1 + n, x) - (b + 1));
	if(all - good <= k) ans = max(ans, all * x);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		ans = -1;

		cin >>n >>k;
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);

		for(int i = 1; i <= n; i ++)
		{
			check(a[i]);
			check(b[i]);
		}
		cout <<ans <<endl;
	}
	return 0;
}