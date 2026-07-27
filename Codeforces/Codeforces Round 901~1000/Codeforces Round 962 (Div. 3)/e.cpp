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

const int N = 2e5 + 10, mod = 1e9 + 7;
int a[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '0') a[i + 1] = a[i] - 1;
			else a[i + 1] = a[i] + 1;
		}
		int ans = 0;

		map <int, int> mp; mp[0] = 1; int len = s.size();
		for(int i = 1; i <= len; i ++)
		{
			ans += (len - i + 1) * mp[a[i]];
			ans %= mod;

			mp[a[i]] += i + 1;
		}
		cout <<ans % mod <<endl;
	}
	return 0;
}