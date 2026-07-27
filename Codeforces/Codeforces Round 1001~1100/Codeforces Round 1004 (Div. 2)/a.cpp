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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int a, b; cin >>a >>b;
		bool f = 0;
		if(b == a + 1)
		{
			cout <<"YES" <<endl;
			continue;
		}
		int c = a - b;
		if(c >= 0 && (c + 1) % 9 == 0)
		{
			f = 1;
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}