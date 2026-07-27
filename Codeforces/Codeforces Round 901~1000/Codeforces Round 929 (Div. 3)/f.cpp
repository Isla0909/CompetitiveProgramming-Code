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
#include <cmath>
#include <ctime>
#include <random>
#include <chrono>
#include <functional>
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[3] = {1, -1, 0}, dy[3] = {0, 0, 1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n, vector<int>(m)); vector<vector<int>> col(m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				cin >>g[i][j];

		queue<pii> q; vector dis(n, vector<int>(m, -1));
		q.emplace(0, 0); dis[0][0] = 0;
		while(q.size())
		{
			auto [x, y] = q.front(); q.pop();
			if(y < m - 1 && g[(x + 1) % n][y + 1] == 0 && dis[(x + 1) % n][y + 1] == -1)
			{
				dis[(x + 1) % n][y + 1] = dis[x][y] + 1;
				q.emplace((x + 1) % n, y + 1);
			}
			if(g[(x + 1) % n][y] == 0 && g[(x + 2) % n][y] == 0 && dis[(x + 2) % n][y] == -1)
			{
				dis[(x + 2) % n][y] = dis[x][y] + 1;
				q.emplace((x + 2) % n, y);
			}
		}
		int ans = INF;
		for(int i = 0; i < n; i ++)
		{
			if(dis[i][m - 1] == -1) continue;

			int x = dis[i][m - 1];

			int now = (n - 1 + x) % n;
			if(i < now) ans = min(ans, x + min(now - i, i + n - now));
			else ans = min(ans, x + min(i - now, now + n - i));
		}
		cout <<((ans == INF) ? -1 : ans) <<endl;
	}
	return 0;
}