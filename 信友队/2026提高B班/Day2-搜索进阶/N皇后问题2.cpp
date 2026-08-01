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

constexpr int N = 14;

char g[N][N];
bool row[N], col[N], dg[2 * N], udg[2 * N];

int n, ans;
void dfs(int x, int y, int s)
{
	if(y == n) y = 0, x ++;
	if(x == n)
	{
		if(s == n) ans ++;
		return ;
	}

	if(!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y])
	{
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
		dfs(x, y + 1, s + 1);
		g[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
	}
	dfs(x, y + 1, s);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >>n;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			g[i][j] = '.';
	dfs(0, 0, 0);
	cout <<ans <<endl;
	return 0;
}
