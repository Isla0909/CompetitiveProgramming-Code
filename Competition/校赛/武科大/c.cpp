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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct cxy
{
	int x, y;
	int d;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, k; cin >>n >>m >>k;
	vector g(n + 1, vector<int>(m + 1));
	vector d(n + 1, vector<int>(m + 1));
	int cnt = 0;
	while(k --)
	{
		int a, b, c; cin >>a >>b >>c;
		for(int i = max(a - c, 1); i <= min(a + c, n); i ++)
			for(int j = max(b - c, 1); j <= min(b + c, m); j ++)
				g[i][j] = 1, cnt ++, d[i][j] = -1;
	}

	if(cnt == n * m)
	{
		cout <<-1 <<endl;
		return 0;
	}
	vector st(n + 1, vector<bool>(m + 1));
	queue<pii> q;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(g[i][j]) q.push({i, j});

	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();
		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && !st[a][b] && !g[a][b])
			{
				st[a][b] = 1;
				d[a][b] = d[x][y] + 1;
				q.push({a, b});
			}
		}
	}
	int ans = -1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			ans = max(ans, d[i][j]);
	cout <<ans <<endl;
	return 0;
}