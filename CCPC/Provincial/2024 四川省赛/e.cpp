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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<char>(m + 1));
		vector f(n + 1, vector<int>(m + 1));
		vector<pii> v;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				char c; cin >>c;
				g[i][j] = c;
				if(c == '.') v.emplace_back(i, j);
			}
		if(v.size() == 1 && v[0].ff == 1 && v[0].se == m)
		{
			bool h = 1;
			int c = 0, s1 = 0, s2 = 0;
			for(int i = 1; i <= n && h; i ++)
				for(int j = 1; j <= m && h; j ++)
				{
					if(g[i][j] == '.') continue;
					if(g[i][j] == 'C')
					{
						c ++;

						int cnt = 0;
						for(int u = 0; u < 4; u ++)
						{
							int a = i + dx[u], b = j + dy[u];
							if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] != 'C' && g[a][b] != '.') cnt ++;
						}
						if(cnt < 2) h = 0;
						continue;
					}

					if(g[i][j] == 'L')
					{
						if(j - 1 < 1 || g[i][j - 1] != 'C') h = 0;
						else f[i][j - 1] ++, s2 ++;
					}
					else if(g[i][j] == 'R')
					{
						if(j + 1 > m || g[i][j + 1] != 'C') h = 0;
						else f[i][j + 1] ++, s2 ++;
					}
					else if(g[i][j] == 'U')
					{
						if(i - 1 < 1 || g[i - 1][j] != 'C') h = 0;
						else f[i - 1][j] ++, s1 ++;
					}
					else
					{
						if(i + 1 > n || g[i + 1][j] != 'C') h = 0;
						else f[i + 1][j] ++, s1 ++;
					}
					if(!h) break;
				}

			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
					if(g[i][j] == 'C' && f[i][j] != 2) h = 0;
			cout <<(h && s1 == s2 && (n * m - 1) % 3 == 0 && c == (n * m - 1) / 3 ? "Yes" : "No") <<endl;
		}
		else cout <<"No" <<endl;
	}
	return 0;
}