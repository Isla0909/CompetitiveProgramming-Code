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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, l, r; cin >>n >>l >>r;
		int a[n + 1];
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector <int> v1, v2;
		for(int i = 1; i <= r; i ++)
			v1.push_back(a[i]);
		for(int i = l; i <= n; i ++)
			v2.push_back(a[i]);
		sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < r - l + 1; i ++)
			ans1 += v1[i], ans2 += v2[i];
		cout <<min(ans1, ans2) <<endl;
	}
	return 0;
}