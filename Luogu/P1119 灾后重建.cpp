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

constexpr int N = 200 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int g[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(g, 0x3f, sizeof g);

	int n, m;
	cin >> n >> m;

	vector<int> t(n + 1);
	for(int i = 1; i <= n; i ++) cin >> t[i];

	for(int i = 1; i <= n; i ++) g[i][i] = 0;

	for(int i = 0; i < m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u ++, v ++;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}

	int q;
	cin >> q;

	int j = 0;
	while(q --)
	{
		int x, y, now;
		cin >> x >> y >> now;
		x ++, y ++;

		while(j + 1 <= n && t[j + 1] <= now)
		{
			j ++;
			for(int a = 1; a <= n; a ++)
				for(int b = 1; b <= n; b ++)
					g[a][b] = min(g[a][b], g[a][j] + g[j][b]);
		}

		if(t[x] > now || t[y] > now || g[x][y] > INF / 2) cout << -1 << endl;
		else cout << g[x][y] << endl;
	}

	return 0;
}