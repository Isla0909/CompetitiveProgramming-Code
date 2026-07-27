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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector g(n, vector<int>(n));
		vector st(n, vector<bool>(n, false));

		function <void(int, int, int, int)> dfs;
		dfs = [&](int x, int y, int u, int idx) -> void
		{
			if(idx < 0) return ;

			g[x][y] = idx;
			st[x][y] = 1;
			int a = x + dx[u], b = y + dy[u];
			if(a >= 0 && a < n && b >= 0 && b < n && !st[a][b])
			{
				dfs(a, b, u, idx - 1);
			}
			else
			{
				u ++;
				if(u == 4) u = 0;
				a = x + dx[u], b = y + dy[u];
				dfs(a, b, u, idx - 1);
			}
		};

		dfs(0, 0, 0, n * n - 1);

		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				cout <<g[i][j] <<" \n"[j == n - 1];
	}
	return 0;
}