#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	vector f(n + 1, vector<int>(n + 1));
	vector g(m + 1, vector<char>(m + 1));

	for(int i = 1; i <= m; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			vector t(m + 1, vector<char>(m + 1));
			for(int i = 1; i <= m; i ++)
				for(int j = 1; j <= m; j ++)
					t[j][m + 1 - i] = g[i][j];

			for(int i = 1; i <= m; i ++)
				for(int j = 1; j <= m; j ++)
					g[i][j] = t[i][j];
		}
		else
		{
			int x, y; cin >>x >>y;
			for(int i = x, u = 1; i <= min(n, x + m - 1); i ++, u ++)
				for(int j = y, k = 1; j <= min(n, y + m - 1); j ++, k ++)
				{
					if(g[u][k] == '#')
						f[i][j] ++;
				}

		}
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cout <<f[i][j] <<" \n"[j == n];
	return 0;
}