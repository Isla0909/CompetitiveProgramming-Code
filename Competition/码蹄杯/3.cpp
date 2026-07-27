#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int x, vector<int> &v)
{
	for(int i = 0; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n = 2, m; cin >>m;
	vector g(n + 1, vector<char>(m + 1));
	vector st(n + 1, vector<bool>(m + 1));

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	auto bfs = [&](int x, int y) -> void
	{
		queue<pii> q; q.push({x, y}); st[x][y] = 1;
		while(q.size())
		{
			auto [x, y] = q.front(); q.pop();
			for(int i = 0; i < 4; i ++)	
			{
				int a = x + dx[i], b = y + dy[i];
				if(a >= 1 && a <= n && b >= 1 && b <= m && !st[a][b] && g[a][b] == g[x][y])
				{
					st[a][b] = 1;
					q.push({a, b});
				}
			}
		}
	};

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(!st[i][j])
			{
				bfs(i, j);
				ans ++;
			}
	cout <<ans <<endl;
	return 0;
}