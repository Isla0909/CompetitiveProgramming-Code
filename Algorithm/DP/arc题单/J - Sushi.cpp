#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 300 + 10, INF = 0x3f3f3f3f;
int cnt[4];
double f[N][N][N];

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
	{
		int x; cin >>x;
		cnt[x] ++;
	}
	for(int k = 0; k <= n; k ++)
	{
		for(int j = 0; j <= n; j ++)
		{
			for(int i = 0; i <= n; i ++)
			{
				if(i || j || k)
				{
					if(i) f[i][j][k] += f[i - 1][j][k] * i / (i + j + k);
					if(j) f[i][j][k] += f[i + 1][j - 1][k] * j / (i + j + k);
					if(k) f[i][j][k] += f[i][j + 1][k - 1] * k / (i + j + k);
					f[i][j][k] += (double) n / (i + j + k);
				}
			}
		}
	}
	printf("%.10lf\n", f[cnt[1]][cnt[2]][cnt[3]]);
	return 0;
}