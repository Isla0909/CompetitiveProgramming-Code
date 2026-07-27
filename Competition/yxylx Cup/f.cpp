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
	int sx, sy;
	vector g(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			cin >>g[i][j];
			if(g[i][j] == 'S') sx = i, sy = j;
		}

	vector<int> d(5, INF);
	vector st(n + 1, vector<int>(m + 1, -1));
	queue<pii> q; 
	q.emplace(sx, sy); st[sx][sy] = 0;
	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();

		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] != '#' && st[a][b] == -1)
			{
				st[a][b] = st[x][y] + 1;
				if(g[a][b] != '.')
				{
					int c = g[a][b] - '0';
					d[c] = st[a][b];
				}
				q.emplace(a, b);
			}
		}
	}
	int ans = -1, s = INF;
	for(int i = 1; i <= 4; i ++)
		if(d[i] < s)
		{
			ans = i;
			s = d[i];
		}
	if(ans == -1) cout <<-1 <<endl;
	else if(ans == 1) cout <<"Naruse Shiroha" <<endl;
	else if(ans == 2) cout <<"Sorakado Ao" <<endl;
	else if(ans == 3) cout <<"Kushima Kamome" <<endl;
	else cout <<"Tsumugi Wenders" <<endl;
	return 0;
}
