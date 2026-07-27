#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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
		map <int, int> mp;

		int n; cin >>n;
		for(int i = 0; i < n; i ++)
		{
			int a, b, c; cin >>a >>b >>c;
			if((b - c) % a == 0)
			{
				int x = (b - c) / a;
				mp[x] ++;
				//cout <<1;
				//cout <<x <<endl;
			}
			if((c - b) % a == 0)
			{
				int x = (c - b) / a;
				mp[x] ++;
				//cout <<2 <<endl;
				//cout <<x <<endl;
			}
			if((b - a) % c == 0)
			{
				int x = (b - a) / c;
				mp[x] ++;
			}
			if((a - b) % c == 0)
			{
				int x = (a - b) / c;
				mp[x] ++;
			}
			if((c - a) % b == 0)
			{
				int x = (c - a) / b;
				mp[x] ++;
			}
			if((a - c) % b == 0)
			{
				int x = (a - c) / b;
				mp[x] ++;
			}
			for(auto x : mp)
			{
				if(x.se >= n && x.ff >= 0)
				{
					cout <<x.ff <<endl;
					break;
				}
			}
		}
	}
	return 0;
}