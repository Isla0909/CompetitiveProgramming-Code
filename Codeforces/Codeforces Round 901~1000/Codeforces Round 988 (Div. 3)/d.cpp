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
pii a[N], b[N];

bool cmp(pii &a, pii &b)
{
	return a.ff < b.ff;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, l; cin >>n >>m >>l;
		for(int i = 1; i <= n; i ++) cin >>a[i].ff >>a[i].se;

		sort(a + 1, a + 1 + n, cmp);

		priority_queue <pii> q;
		for(int i = 1; i <= m; i ++)
		{
			cin >>b[i].ff >>b[i].se;
			q.emplace(b[i].se, b[i].ff);
		}

		int sum = 1, ans = 0; bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			stack <pii> s;
			while(q.size())
			{
				if(sum > a[i].se - a[i].ff + 1) break;

				auto t = q.top();
				if(t.se < a[i].ff)
				{
					sum += t.ff;
					ans ++;
					q.pop();
				}
				else
				{
					s.push(t); q.pop();
				} 

			}
			if(sum <= a[i].se - a[i].ff + 1)
			{
				f = 0;
				break;
			}
			while(s.size())
			{
				auto t = s.top(); s.pop(); 
				q.push(t);
			}
		}
		if(f) cout <<ans <<endl;
		else cout <<-1 <<endl;
	}
	return 0;
}