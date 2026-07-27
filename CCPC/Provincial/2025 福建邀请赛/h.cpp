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

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

struct cxy
{
	int x, y;
	int c;
	cxy(int x, int y, int c) : x(x), y(y), c(c) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		int l, r; cin >>l >>r;
		vector g(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				char c; cin >>c;
				g[i][j] = c - '0';
			}

		vector d(n + 1, vector<array<int, 2>>(m + 1, {INF, INF}));
		d[1][1][0] = 0;
		queue<cxy> q; q.emplace(1, 1, 0);
		while(q.size())
		{
			auto [x, y, c] = q.front(); q.pop();
			for(int i = 0; i < 8; i ++)
			{
				int a = x + dx[i], b = y + dy[i];
				if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] && d[a][b][c ^ 1] == INF)
				{
					d[a][b][c ^ 1] = d[x][y][c] + 1;
					q.emplace(a, b, c ^ 1);
				}
			}
		}

		int dist = min(d[n][m][1], d[n][m][0]);
		//cout <<"d1 " <<d[n][m][1] <<" d2 " <<d[n][m][0] <<endl; 
		if(dist == INF) cout <<-1 <<endl;
		else if(l != r) cout <<(dist + r - 1) / r <<endl;
		else
		{	
			int x = l;

			int t1 = INF, t2 = INF;
			if(d[n][m][1] != INF && (r & 1))
			{
				int l = 0, r = 1e6 + 10;
				while(l + 1 != r)
				{
					int mid = l + r >> 1;
					if(1LL * (2 * mid - 1) * x >= d[n][m][1]) r = mid;
					else l = mid;
				}
				t1 = 2 * r - 1;
			}
			if(d[n][m][0] != INF)
			{
				if(x & 1)
				{
					int l = 0, r = 1e6;
					while(l + 1 != r)
					{
						int mid = l + r >> 1;
						if(2LL * mid * x >= d[n][m][0]) r = mid;
						else l = mid;
					}
					t2 = 2 * r;
				}
				else t2 = (d[n][m][0] + x - 1) / x;
			}
			int ans = min(t1, t2);
			cout <<(ans == INF ? -1 : ans) <<endl;
		}
	}
	return 0;
}
