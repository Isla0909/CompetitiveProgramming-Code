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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 500 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int f[N][N][12];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >>n >>m >>k;
	vector g(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	memset(f, 0x3f, sizeof f);

	f[1][1][0] = g[1][1], f[1][1][1] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			for(int u = 0; u <= k; u ++)
			{
				if(j - 1 >= 1)
				{	
					f[i][j][u] = max(f[i][j - 1][u], g[i][j]);
					if(u >= 1) f[i][j][u] = min(f[i][j][u], f[i][j - 1][u - 1]);
				}
				if(i - 1 >= 1)
				{
					f[i][j][u] = min(f[i][j][u], max(f[i - 1][j][u], g[i][j]));
					if(u >= 1) f[i][j][u] = min(f[i][j][u], f[i - 1][j][u - 1]);
				}
			}
	
	int ans = INF;
	for(int u = 0; u <= k; u ++)
		ans = min(ans, f[n][m][u]);
	cout <<ans <<endl;
	return 0;
}