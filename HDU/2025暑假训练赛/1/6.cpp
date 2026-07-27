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

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
	auto [x1, y1, z1] = a;
	auto [x2, y2, z2] = b;
	return z1 < z2;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];

		vector d(n + 1, vector<int>(m + 1));
		queue<tuple<int, int, int>> q; q.emplace(1, 1, g[1][1]);
		while(q.size())
		{
			auto [x, y, h] = q.front(); q.pop();

			if(d[x][y]) continue;
			d[x][y] = 1;

			for(int i = 0; i < 4; i ++)
			{
				int a = x + dx[i], b = y + dy[i];
				if(a >= 1 && a <= n && b >= 1 && b <= m && !d[a][b] && g[a][b] < h)
					q.emplace(a, b, g[a][b]);
			}
		}
		vector<pii> v;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(!d[i][j]) v.emplace_back(g[i][j], i * 110 + j);

		sort(v.begin(), v.end(), greater<pii>());
		for(auto [h, c] : v)
		{
			//cout <<"h c" <<h <<" " <<c / 110 <<" " <<c % 110 <<endl;
			q.emplace(c / 110, c % 110, h);
		}

		ll ans = 0; vector<tuple<int, int, int>> u; u.emplace_back(1, 1, g[1][1]);
		while(q.size())
		{
			auto [x, y, h] = q.front(); q.pop();

			//cout <<x <<" " <<y <<" " <<h <<endl;

			if(!d[x][y])
			{
				d[x][y] = 1;
				ans += (1LL << 34);
				u.emplace_back(x, y, g[x][y]);
			}

			for(int i = 0; i < 4; i ++)
			{
				int a = x + dx[i], b = y + dy[i];
				//if(a == 2 && b == 1) cout <<"sadas" <<endl;
				if(a >= 1 && a <= n && b >= 1 && b <= m && !d[a][b] && g[a][b] < h)
				{
					q.emplace(a, b, g[a][b]);
					d[a][b] = 1;

					//cout <<a <<" a b " <<b <<endl;
				}
			}
		}
		sort(u.begin(), u.end(), cmp);

		for(int i = 1; i < u.size(); i ++)
		{
			auto [x1, y1, z1] = u[i];
			auto [x2, y2, z2] = u[i - 1];
			//cout <<x1 <<" " <<y1 <<" " <<z1 <<endl;
			ans += 114 * abs(x1 - x2) + 5141 * abs(y1 - y2) + 919810LL * abs(z1 - z2);
		}
		cout <<ans <<endl;
	}
	return 0;
}