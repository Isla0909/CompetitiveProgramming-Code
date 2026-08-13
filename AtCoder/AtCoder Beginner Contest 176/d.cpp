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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	int sx, sy, ex, ey; cin >>sx >>sy >>ex >>ey;
	sx --, sy --, ex --, ey --;

	vector<string> g(n);
	for(auto &s : g) cin >>s;

	vector dist(n, vector<int>(m, INF));
	deque<pii> q;

	dist[sx][sy] = 0;
	q.push_front({sx, sy});

	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	while(q.size())
	{
		auto [x, y] = q.front(); q.pop_front();
		for(int i = 0; i < 4; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#')
			{
				if(dist[x][y] >= dist[nx][ny]) continue;
				dist[nx][ny] = dist[x][y];
				q.push_front({nx, ny});
			}
		}

		for(int dx = -2; dx <= 2; dx ++)
			for(int dy = -2; dy <= 2; dy ++)
			{
				int nx = x + dx, ny = y + dy;
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#')
				{
					if(dist[x][y] + 1 >= dist[nx][ny]) continue;
					dist[nx][ny] = dist[x][y] + 1;
					q.push_back({nx, ny});
				}
			}
	}
	if(dist[ex][ey] == INF) cout <<-1 <<endl;
	else cout <<dist[ex][ey] <<endl;
	return 0;
}
