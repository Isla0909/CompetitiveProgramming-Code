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
		int n, m; cin >>n >>m;

		priority_queue <int> a, b;
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			a.push(x);
		}
		for(int i = 0; i < m; i ++)
		{
			int x; cin >>x;
			b.push(x);
		}
		bool f = 1;
		while(a.size())
		{
			if(a.size() < b.size() || !b.size())
			{
				f = 0;
				break;
			}
			int t = a.top(); 
			if(t > b.top())
			{
				f = 0;
				break;
			}
			if(t == b.top())
			{
				a.pop();
				b.pop();
			}
			else
			{
				int x = b.top(); b.pop();
				b.push(x / 2);
				b.push((x + 1) / 2);
			}
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}