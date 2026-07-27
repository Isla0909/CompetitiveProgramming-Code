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

constexpr int N = 1000 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m;

char g[N][N];
int st[N][N];

vector<string> ans;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
string s = "";

void dfs(int x, int y, int d)
{
	if(x == n && y == m)
	{
		ans.push_back(s);
		return ;
	}

	st[x][y] = d;

	for(int i = 0; i < 4; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] == '0' && d + 1 <= st[a][b])
		{
			if(i == 0) s.push_back('D');
			if(i == 1) s.push_back('R');
			if(i == 2) s.push_back('U');
			if(i == 3) s.push_back('L');
			dfs(a, b, d + 1);
			s.pop_back();
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(st, 0x3f, sizeof st);

	cin >>n >>m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	dfs(1, 1, 1);

	sort(ans.begin(), ans.end(), [&](auto a, auto b)
	{
		if(a.size() != b.size()) return a.size() < b.size();
		return a < b;
	});
	cout <<ans[0] <<endl;
	return 0;
}
