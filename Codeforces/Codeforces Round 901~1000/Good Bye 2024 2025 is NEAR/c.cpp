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
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

pii solve(int l, int r, int k)
{
	if(r - l + 1 < k) return {0, 0};
	if((r - l + 1) & 1)
	{
		pii x = solve(1, (l + r >> 1) - 1, k);
		int ans = (l + r >> 1) * x.se + x.ff;
		return {x.ff + ans + (l + r >> 1), x.se * 2 + 1};
	}
	else
	{
		pii x = solve(l, (l + r >> 1), k);
		int ans = (l + r >> 1) * x.se + x.ff;
		return {x.ff + ans, x.se * 2};
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		cout <<solve(1, n, k).ff <<endl;
	}
	return 0;
}