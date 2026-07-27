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

const int N = 3e3 + 10, INF = 0x3f3f3f3f;
int f[N][N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	string s, p; cin >>s >>p;

	int n = s.size(), m = p.size(); int mmax = -1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(s[i - 1] == p[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	//cout <<f[n][m] <<endl;

	string lcs = "";
	int i = n, j = m;
	while(i >= 1 && j >= 1)
	{
		if(s[i - 1] == p[j - 1])
		{
			lcs = s[i - 1] + lcs;
			i --, j --;
		}
		else if(f[i - 1][j] > f[i][j - 1]) i --;
		else j --;
	}
	cout <<lcs <<endl;
	return 0;
}