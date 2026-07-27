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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int a[n + 1];
		int s0 = 0, s1 = 0;
		priority_queue <int> q0;
		priority_queue <int> q1;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(a[i] == 0)
			{
			    s0 ++;
			    q0.push(i);
			}
			else if(a[i] == 1)
			{
			    s1 ++;
			    q1.push(i);
			}
		}

		vector <pii> v;
		int x = 0, y = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(x == s0 && y == s1) break;
			if(a[i] == 0)
			{
			    x ++;
			    continue;
			}
			if(a[i] == 1)
			{
				if(x < s0)
				{
				    int t = q0.top(); q0.pop();
					v.emplace_back(i, t);
					swap(a[i], a[t]);
					q1.push(t);
					x ++;
				}
				else y ++;
			}
			else
			{
				if(y < s1)
				{
				    int t = q1.top(); q1.pop();
					v.emplace_back(i, t);
					swap(a[i], a[t]);
					if(x == s0) y ++;
					else i --;
				}
			}
		}
		cout <<v.size() <<endl;
		for(auto x : v)
			cout <<x.ff <<" " <<x.se <<endl;	
	} 
	return 0;
}