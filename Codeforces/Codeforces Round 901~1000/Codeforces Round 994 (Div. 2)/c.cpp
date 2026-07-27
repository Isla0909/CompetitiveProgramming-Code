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
int a[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, x, y; cin >>n >>x >>y;

		x --, y --;
		a[x] = 0, a[y] = 1;
		
		for(int i = x; i != y; i = (i + 1) % n)
		{
		    a[i] = (i - x + n) % n % 2;
		    if((i + 1) % n == y && a[i] == 1) a[i] = 2;
		}
		
		for(int i = x; i != y; i = (i - 1 + n) % n)
		{
		    a[i] = (x - i + n) % n % 2;
		    if((i - 1 + n) % n == y && a[i] == 1) a[i] = 2;
		}
		for(int i = 0; i < n; i ++)
		    cout <<a[i] <<" \n"[i == n - 1];
	}
	return 0;
}