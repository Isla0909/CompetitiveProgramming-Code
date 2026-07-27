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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

bool check(int x)
{
	int l = log2(x);
	if(x == (1 << l)) return 1;
	for(int i = 0; i <= l; i ++)
		if((x >> i & 1) == 0) return 0;
	return 1;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int x; cin >>x;

		if(x <= 4 || check(x))
		{
			cout <<-1 <<endl;
			continue;
		}
		if(x == 5)
		{
			cout <<3 <<endl;
			continue;
		}
		int l = log2(x);
		int ans = 0;
		for(int i = 0; i <= l; i ++)
		{
			if((x >> i & 1) == 0)
			{
				ans |= (1 << i);
				for(int t = 1; ; t ++)
				{
					int a = i - t;
					if(a >= 0 && (x >> a & 1))
					{
						ans |= (1 << a);
						break;
					}
					int b = i + t;
					if(x >> b & 1)
					{
						ans |= (1 << b);
						break;
					}
				}
				break;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}