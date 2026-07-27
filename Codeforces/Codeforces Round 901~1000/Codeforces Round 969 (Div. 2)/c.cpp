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
int c[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, a, b; cin >>n >>a >>b;
		int p = __gcd(a, b);
		for(int i = 1; i <= n; i ++)
		{
			cin >>c[i];
			c[i] %= p;
		}
		//tell(c, n);
		sort(c + 1, c + 1 + n);
		//tell(c, n);
		//cout <<p <<endl;
		int ans = c[n] - c[1];
		for(int i = 1; i < n; i ++)
			ans = min(ans, c[i] + p - c[i + 1]);
		cout <<ans <<endl;
	}
	return 0;
}