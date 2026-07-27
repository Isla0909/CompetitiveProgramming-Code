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

constexpr int N = 500 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct cxy
{
	int x, y, s;
	cxy(int x, int y, int s) : x(x), y(y), s(s) {}
};

int d[N][N][2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	int x, y, ex, ey;
	vector g(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			cin >>g[i][j];
			if(g[i][j] == 'S') x = i, y = j;
			if(g[i][j] == 'G') ex = i, ey = j;
		}

	
	queue<cxy> q; d[x][y][0] = 1;
	q.emplace(x, y, 0);
	while(q.size())
	{
		auto [x, y, s] = q.front(); q.pop();
		//cout <<x <<" " <<y <<" " <<d[x][y][s] <<" " <<s <<endl;
		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a < 1 || a > n || b < 1 || b > m || g[a][b] == '#') continue;
			//cout <<a <<" " <<b <<endl;
			if(g[a][b] == 'x' && s)
			{
				if(d[a][b][s]) continue;
				d[a][b][s] = d[x][y][s] + 1;
				q.emplace(a, b, s);
			}
			if(g[a][b] == 'o' && !s)
			{
				if(d[a][b][s]) continue;
				d[a][b][s] = d[x][y][s] + 1;
				q.emplace(a, b, s);
			}
			if(g[a][b] == '.')
			{
				if(d[a][b][s]) continue;
				d[a][b][s] = d[x][y][s] + 1;
				q.emplace(a, b, s);
			}
			if(g[a][b] == '?')
			{
				if(d[a][b][s ^ 1]) continue;
				d[a][b][s ^ 1] = d[x][y][s] + 1;
				q.emplace(a, b, s ^ 1);
			}
			if(g[a][b] == 'S')
			{
				if(d[a][b][s]) continue;
				d[a][b][s] = d[x][y][s] + 1;
				q.emplace(a, b, s);
			}
			if(g[a][b] == 'G')
			{
				cout <<d[x][y][s] <<endl;
				return 0;
			}
		}
	}
	cout <<-1 <<endl;
	return 0;
}