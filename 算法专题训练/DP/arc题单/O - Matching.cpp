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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int g[30][30];


void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			cin >>g[i][j];

	int m = 1 << n;
	vector f(n + 1, vector<int>(m));
	f[0][0] = 1;

	for(int i = 1; i <= n; i ++)
	{
		for(int t = 0; t <= m - 1; t ++)
		{
			if(i != __builtin_popcount(t)) continue;
			for(int j = 0; j < n; j ++)
			{
				if((t >> j) & 1 == 0 || !g[i - 1][j]) continue;
				f[i][t] += f[i - 1][t ^ (1 << j)];
				f[i][t] %= mod;
			}
		}
	}
	cout <<f[n][m - 1] <<endl;
	return 0;
}