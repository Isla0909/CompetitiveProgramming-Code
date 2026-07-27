#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

map <pii, bool> mp;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		mp.clear(); 
		int n; cin >>n;
		vector <int> d(n + 1, 0);
		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			d[a] ++, d[b] ++;
			if(a > b) swap(a, b);
			mp[{a, b}] = 1;
		}
		vector <pii> v;
		for(int i = 1; i <= n; i ++)
			v.emplace_back(d[i], i);
		
		sort(v.begin(), v.end(), greater<pii>());

		int ans = -1;
		for(int i = 0; i < 2; i ++)
		{
			for(int j = i + 1; j < n; j ++)
			{
				int a = v[i].se, b = v[j].se;
				if(a > b) swap(a, b);
				ans = max(ans, d[a] + d[b] - 1 - mp[{a, b}]);
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}