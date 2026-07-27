#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		int l, r; cin >>l >>r;
		int a = 0, b = 0, c = 0;

		for(int i = 29; i >= 0; i --)
		{
			if((l ^ r) >> i & 1)
			{
				b |= 1 << i;
				a |= (1 << i) - 1;
				break;
			}
			else
			{
				a |= l & (1 << i);
				b |= l & (1 << i);
			}
		}
		c = l;
		while(c == a || c == b) c ++;
		cout <<a <<" " <<b <<" " <<c <<endl;
	}
	return 0;
}