#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int a[N], b[N];

bool check(int x, int y, int z)
{
	if(x - y < z) return 1;
	return 0;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= m; i ++) cin >>b[i];

		sort(b + 1, b + 1 + m);

		int x = b[1], y = b[m];

		bool f = 1;
		a[1] = min(a[1], x - a[1]);

		for(int i = 2; i <= n; i ++)
		{
			int l = 0, r = m + 1;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(check(b[mid], a[i], a[i - 1])) l = mid;
				else r = mid;
			}

			if(l == m && b[l] - a[i] < a[i] && a[i] < a[i - 1]) 
			{
				f = 0;
				break;
			}
			if(a[i] >= a[i - 1] && l != m) a[i] = min(a[i], b[r] - a[i]); 
			else if(l != m) a[i] = b[r] - a[i];

			if(a[i] < a[i - 1])
			{
				f = 0;
				break;
			}

		}
		// for(int i = 1; i <= n; i ++)
		// 	cout <<a[i] <<" \n"[i == n];
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl; 

	}
	return 0;
}