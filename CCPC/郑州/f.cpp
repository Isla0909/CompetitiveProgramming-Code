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

struct cxy
{
	int x, y;
	int state;
	int k;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<char>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];

		auto check = [&](int x) -> bool
		{
			vector st(n + 1, vector<int>(m + 1, -1));
			deque<cxy> q; q.push_front({1, 1, 0, x}); st[1][1] = x;
			while(q.size())
			{
				auto [x, y, f, k] = q.front(); q.pop_front();
				//cout <<x <<" " <<y <<" " <<f <<" " <<k <<endl;
				if(x == n && y == m) return true;

				for(int i = 0; i < 4; i ++)
				{
					int a = x + dx[i], b = y + dy[i];
					if(a >= 1 && a <= n && b >= 1 && b <= m)
					{
						//cout <<a <<" " <<b <<endl;
						if(f == 0)
						{
							if(g[a][b] == '.' && st[a][b] < k)
							{
								st[a][b] = k;
								q.push_front({a, b, 0, k});
								//cout <<"push" <<a <<" " <<b <<" " <<0 <<" " <<k <<endl;
							}
							else if(g[a][b] == '#' && st[a][b] < k && k > 0)
							{
								st[a][b] = k - 1;
								q.push_back({a, b, 1, k - 1});
							}
						}
						else
						{
							if(k > 0)
							{
								if(k - 1 > st[a][b])
								{
									st[a][b] = k - 1;
									q.push_back({a, b, 1, k - 1});
								}
							}
							else
							{
								if(g[a][b] == '.' && st[a][b] == -1)
								{
									st[a][b] = 0;
									q.push_front({a, b, 1, 0});
								}
							}
						}
					}
				}
			}
			return false;
		};

		int l = -1, r = n * m;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			//cout <<l <<" l and r " <<r <<" " <<mid <<endl;
			if(check(mid)) r = mid;
			else l = mid;
		}
		cout <<r <<endl;
	}
	return 0;
}
// 9 2
// ..
// #.
// ##
// ..
// ..
// ..
// ##
// .#
// #.