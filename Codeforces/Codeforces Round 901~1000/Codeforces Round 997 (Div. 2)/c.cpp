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
		if(n == 6)
		{
			cout <<"1 1 2 3 1 2" <<endl;
			continue;
		}
		int t = n - 4, x = 3;
		cout <<"1 2 ";
		while(t --)
		{
			cout <<x <<" ";
			x ++;
		}
		cout <<"1 2" <<endl;
	}
	return 0;
}