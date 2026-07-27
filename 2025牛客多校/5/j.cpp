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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector dis(n + 1, vector<int>(m + 1, INF));
	queue<pii> q;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			int x; cin >>x;
			if(x)
			{
				q.push({i, j});
				dis[i][j] = 0;
			}
		}
	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();

		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && dis[a][b] == INF)
			{
				dis[a][b] = dis[x][y] + 1;
				q.push({a, b});
			}
		}
	}

	int l = -1, r = n + m + 1;
	while(l + 1 != r)
	{
		int d = l + r >> 1;

		int a = INF, A = -INF, b = INF, B = -INF;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(dis[i][j] > d)
				{
					a = min(a, i + j);
					A = max(A, i + j);
					b = min(b, i - j);
					B = max(B, i - j);
				}
		if(A - a <= 2 * d && B - b <= 2 * d && (A - a < 2 * d || B - b < 2 * d || (A + a) / 2 % 2 == (B + b + 2000000) / 2 % 2)) r = d;
		else l = d;
	}
	cout <<r <<endl;
	return 0;
}