#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#define endl '\n'
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int tot = n * m;

	// adj[u]：u 被哪些单元格依赖
	// pair.first 是目标单元格，pair.second 是正负号
	vector<vector<pii>> adj(tot);
	vector<int> deg(tot);
	vector<i64> val(tot);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			string s;
			cin >> s;

			int u = i * m + j;
			int p = 0;

			while(p < s.size())
			{
				int sign = 1;

				if(s[p] == '+')
				{
					sign = 1;
					p++;
				}
				else if(s[p] == '-')
				{
					sign = -1;
					p++;
				}

				if(isupper(s[p]))
				{
					int col = s[p] - 'A';
					p++;

					int row = 0;

					while(p < s.size() && isdigit(s[p]))
					{
						row = row * 10 + s[p] - '0';
						p++;
					}

					row--;

					int v = row * m + col;

					// u 依赖 v，所以建边 v -> u
					adj[v].emplace_back(u, sign);
					deg[u]++;
				}
				else
				{
					i64 x = 0;

					while(p < s.size() && isdigit(s[p]))
					{
						x = x * 10 + s[p] - '0';
						p++;
					}

					val[u] += sign * x;
				}
			}
		}
	}

	queue<int> q;

	for(int i = 0; i < tot; i++)
	{
		if(deg[i] == 0)
			q.emplace(i);
	}

	vector<bool> ok(tot);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		ok[u] = true;

		for(auto [v, sign] : adj[u])
		{
			val[v] += sign * val[u];

			deg[v]--;

			if(deg[v] == 0)
				q.emplace(v);
		}
	}
    cout << n <<" " << m <<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int id = i * m + j;

			if(ok[id])
				cout << val[id];
			else
				cout << "ERROR";

			cout << " \n"[j == m - 1];
		}
	}

	return 0;
}