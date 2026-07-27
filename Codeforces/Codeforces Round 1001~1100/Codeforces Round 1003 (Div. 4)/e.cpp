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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;

		int x = abs(n - m);
		x --;
		if(1 + x > k || k > max(n, m))
		{
			cout <<-1 <<endl;
			continue;
		}
		if(k == 1)
		{
			if(m > n)
			{
				cout <<1;
				for(int i = 0; i < n; i ++)
					cout <<"01";
			}
			else if(m < n)
			{
				cout <<0;
				for(int i = 0; i < m; i ++)
					cout <<"10";
			}
			else
			{
				for(int i = 1; i <= n; i ++)
					cout <<"01";
			}

		}
		else if(k == 0)
		{
			for(int i = 1; i <= n; i ++)
				cout <<"01";
		}
		else
		{
			if(n >= k && n > m)
			{
				int t = k - 1;
				while(t --) cout <<0;

				n -= k - 1;
				while(n || m)
				{
					if(n)
					{
						cout <<0;
						n --;
					}
					if(m)
					{
						cout <<1;
						m --;
					}
				}
			}
			else
			{
				int t = k - 1;
				while(t --) cout <<1;

				m -= k - 1;
				while(n || m)
				{
					
					if(m)
					{
						cout <<1;
						m --;
					}
					if(n)
					{
						cout <<0;
						n --;
					}
				}
			}
		}
		cout <<endl;
	}
	return 0;
}