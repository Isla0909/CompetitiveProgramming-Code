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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct cxy
{
	int x, y, d;
	cxy() {}
	cxy(int x, int y, int d) : x(x), y(y), d(d) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, aa, bb; cin >>n >>m >>aa >>bb;
	vector st(n + 1, vector<int>(m + 1)), dis(n + 1, vector<int>(m + 1, INF * 2));
	vector t(n + 1, vector<int>(m + 1));
	queue<cxy> q;
	for(int i = 0; i < aa; i ++)
	{
		int x, y; cin >>x >>y;
		q.emplace(x, y, 0);
		st[x][y] = 1;
		dis[x][y] = 0;
	}
	for(int i = 0; i < bb; i ++)
	{
		int x, y, c; cin >>x >>y >>c;
		t[x][y] = c;
		st[x][y] = 2;
	}
	while(q.size())
	{
		auto [x, y, d] = q.front(); q.pop();
		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && dis[a][b] == 2 * INF)
			{
				if(!st[a][b])
				{
					dis[a][b] = d + 1;
					st[a][b] = 1;
					q.emplace(a, b, d + 1);
				}
				else if(st[a][b] == 2)
				{
					if(t[a][b] <= d + 1)
					{
						dis[a][b] = d + 1;
						st[a][b] = 1;
						q.emplace(a, b, d + 1);
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			int cnt = 0;
			for(int u = 0; u < 4; u ++)
			{
				int x = i + dx[u], y = j + dy[u];
				if(x >= 1 && x <= n && y >= 1 && y <= m && st[x][y] != 1) cnt ++;
			}
			if(cnt)
			{
				q.emplace(i, j, dis[i][j]);
				//cout <<i <<" " <<j <<" " <<dis[i][j] <<endl;
			}
		}
	while(q.size())
    {
        auto [x, y, d] = q.front(); q.pop();
        //cout <<x <<" " <<y <<" " <<d <<endl;
        for(int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 1 && a <= n && b >= 1 && b <= m && st[a][b] != 1)
            {
                //cout <<"????" <<endl;
                if(!st[a][b])
                {
                    int nd = dis[x][y] + 1;
                    if(dis[a][b] > nd)
                    {
                        dis[a][b] = nd;
                        q.emplace(a, b, nd);
                    }
                }
                else
                {
                    int nd = max(dis[x][y] + 1, t[a][b]);
                    if(dis[a][b] > nd)
                    {
                        dis[a][b] = nd;
                        q.emplace(a, b, nd);
                    }
                }
            }
        }
    }
    int s = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            s = max(s, dis[i][j]);
    cout <<s <<endl;
	return 0;
}
