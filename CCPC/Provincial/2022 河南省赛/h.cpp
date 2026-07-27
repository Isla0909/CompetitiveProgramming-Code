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

struct cxy
{
	int x, y, c;
	cxy() {}
	cxy(int x, int y, int c) : x(x), y(y), c(c) {}
};

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int m, x, y; cin >>m >>x >>y;
		vector g(4, vector<char>(m + 1));
		for(int i = 2; i <= 3; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];
		int n = 4;
		vector st(4 + 1, vector<int>(m + 2));
		queue<pii> q; q.emplace(1, x);
		st[1][x] = 1;
		while(q.size())
		{
			auto [a, b] = q.front(); q.pop();
			if(a == 1 || a == 4 || b == 0 || b == m + 1) continue;

			for(int i = 0; i < 4; i ++)
			{
				int nx = a + dx[i], ny = b + dy[i];
				if(nx >= 2 && nx <= 3 && ny >= 1 && nny <= m)
				{
					char c = g[nx][ny];
					if(c == 'I')
					{

					}
				}
			}
		}
	}
	return 0;
}
