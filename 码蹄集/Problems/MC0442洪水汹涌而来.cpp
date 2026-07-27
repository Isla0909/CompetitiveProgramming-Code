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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >>n >>m >>k;
	vector g(n + 2, vector<char>(m + 2, '*'));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>g[i][j];

	vector st(n + 2, vector<int>(m + 2));
	queue<pii> q;
	for(int i = 0; i <= n + 1; i ++)
		for(int j = 0; j <= m + 1; j ++)
			if(g[i][j] == '*')
			{
				q.emplace(i, j);
				st[i][j] = 1;
			}
		
	int ans = 0;
	while(q.size())
	{
		auto [x, y] = q.front(); q.pop();

		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] == '.' && !st[a][b])
			{
				st[a][b] = 1;
				ans ++;
				q.emplace(a, b);
			}
		}
	}
	while(k --)
	{
		int x, y; cin >>x >>y;
		if(!st[x][y])
		{
			g[x][y] = '.';
			for(int i = 0; i < 4; i ++)
			{
				int a = x + dx[i], b = y + dy[i];
				if(st[a][b])
				{
					q.emplace(a, b);
				}
			}
			while(q.size())
			{
				auto [x, y] = q.front(); q.pop();

				for(int i = 0; i < 4; i ++)
				{
					int a = x + dx[i], b = y + dy[i];
					if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] == '.' && !st[a][b])
					{
						st[a][b] = 1;
						ans ++;
						q.emplace(a, b);
					}
				}
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}