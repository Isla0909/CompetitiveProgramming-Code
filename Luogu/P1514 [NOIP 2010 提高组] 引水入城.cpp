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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	vector st(n + 1, vector<bool>(m + 1));
	queue<pii> q;
	for(int j = 1; j <= m; j ++)
	{
		q.emplace(1, j);
		st[1][j] = true;
	}

	auto check = [&](int x, int y) -> bool
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();

		for(int i = 0; i < 4; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(check(nx, ny) && !st[nx][ny] && g[x][y] > g[nx][ny])
			{
				st[nx][ny] = true;
				q.emplace(nx, ny);
			}

		}
	}

	int bad = m;
	for(int j = 1; j <= m; j ++)
		if(st[n][j]) bad --;
	if(bad)
	{
		cout <<0 <<endl;
		cout <<bad <<endl;
		return 0;
	}
	cout <<1 <<endl;

	vector l(n + 1, vector<int>(m + 1, INF)), r(n + 1, vector<int>(m + 1, -INF));
	vector deg(n + 1, vector<int>(m + 1));

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(i == n) l[i][j] = r[i][j] = j;

			for(int k = 0; k < 4; k ++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if(check(nx, ny) && g[i][j] > g[nx][ny]) deg[i][j] ++;
			}
		}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(!deg[i][j]) q.emplace(i, j);

	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();

		for(int i = 0; i < 4; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(check(nx, ny) && g[nx][ny] > g[x][y])
			{
				l[nx][ny] = min(l[nx][ny], l[x][y]);
				r[nx][ny] = max(r[nx][ny], r[x][y]);

				deg[nx][ny] --;
				if(!deg[nx][ny]) q.emplace(nx, ny);
			}
		}
	}

	vector<pii> seg;
	for(int j = 1; j <= m; j ++)
		if(l[1][j] != INF)
			seg.emplace_back(l[1][j], r[1][j]);

	sort(seg.begin(), seg.end());

	int now = 1, res = 0, j = 0;
	while(now <= m)
	{
		int r = now - 1;
		while(j < seg.size() && seg[j].ff <= now)
		{
			r = max(r, seg[j].se);
			j ++;
		}

		res ++;
		now = r + 1;
	}
	cout <<res <<endl;
	return 0;
}
