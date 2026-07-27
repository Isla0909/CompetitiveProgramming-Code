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
		int n, k; cin >>n >>k;
		
		int a[n]; int s = 0;

		for(int i = 0; i < n; i ++)
			s |= i;
		if(s == k)
		{
			for(int i = 0; i < n; i ++)
				cout <<i <<" \n"[i == n - 1];
			continue;
		}

		if(n == 1)
		{
			cout <<k <<endl;
			continue;
		}
		else
		{
			a[0] = k, a[1] = 0; int idx = 0;
			for(int i = 2; i < n; i ++)
			{
				int t = k | (idx + 1);
				if(t == k) idx ++;
				else break;
			}

			if(idx == 0)
			{
				for(int i = 2; i < n; i ++) a[i] = 0;

				for(int i = 0; i < n; i ++)
					cout <<a[i] <<" \n"[i == n - 1];
			}
			else
			{
				cout <<0 <<" " <<k <<" ";
				int t = n - 2; int j = 1;
				while(t --)
				{
					cout <<j <<" ";
					if(j == idx) j = 0;

					j ++;
				}
				cout <<endl;
			}
		}
	}
	return 0;
}