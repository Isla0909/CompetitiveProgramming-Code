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
#define int long long
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
		int n; cin >>n;

		int s = 0;
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			s += x;
		}

		int h = 0;
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			h -= x;
		}
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			h += x;
		}
		cout <<h / s <<endl;
	}
	return 0;
}