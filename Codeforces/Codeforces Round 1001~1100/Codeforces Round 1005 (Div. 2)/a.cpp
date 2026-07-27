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
		string s; cin >>s;
		int x = 1; int cnt = 0;
		for(int i = 0; s[i]; i ++)
		{
			int v = s[i] - '0';
			if(v == x)
			{
			     cnt ++;
			int j;
			for(j = i + 1; s[j]; j ++)
			{
			    int y = s[j] - '0';
				if(y != x)
				{
					i = j - 1;
					break;
				}
			}
			if(j == s.size()) break;
			x = 1 - x;
			}
		}
		cout <<cnt <<endl;
	}
	return 0;
}