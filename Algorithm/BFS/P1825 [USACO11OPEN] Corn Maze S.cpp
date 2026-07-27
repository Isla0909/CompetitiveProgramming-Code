#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<char>(m + 1));
	vector<vector<pii>> to(26); int sx = -1, sy = -1;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			cin >>g[i][j];
			if(g[i][j] == '@') sx = i, sy = j;
			else if(g[i][j] >= 'A' && g[i][j] <= 'Z') to[g[i][j] - 'A'].push_back({i, j});
		}

	vector trans(n + 1, vector<pii>(m + 1, {-1, -1}));//传送门连接的点
	for(int i = 0; i < 26; i ++)
	{
		if(!to[i].size()) continue;

		auto [a, b] = to[i].front(); auto [c, d] = to[i].back();
		trans[a][b] = {c, d}, trans[c][d] = {a, b};
	}

	auto bfs = [&]() -> void
	{
		queue<pii> q;
		vector d(n + 1, vector<int>(m + 1));
		d[sx][sy] = 1; q.push({sx, sy});
		while(q.size())
		{
			auto [x, y] = q.front(); q.pop();
			if(g[x][y] == '=')
			{
				cout <<d[x][y] - 1 <<endl;
				break;
			}
			for(int i = 0; i < 4; i ++)
			{
				int a = x + dx[i], b = y + dy[i];
				if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] != '#' && !d[a][b])
				{
					d[a][b] = d[x][y] + 1;

					if(trans[a][b].first != -1)
					{
						auto [x1, y1] = trans[a][b];
						d[x1][y1] = d[a][b];
						q.push({x1, y1});
					}
					else q.push({a, b});

				}
			}
			
		}
	};

	bfs();

	return 0;
}