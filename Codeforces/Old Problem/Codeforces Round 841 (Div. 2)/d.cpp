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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];

		auto check = [&](int x) -> bool
		{
			vector s(n + 1, vector<int>(m + 1));
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
					s[i][j] = s[i - 1][j] + s[i][j - 1] -  s[i - 1][j - 1] + (g[i][j] >= x);
			for(int i = 1; i + x - 1 <= n; i ++)
				for(int j = 1; j + x - 1 <= m; j ++)
				{
					int x1 = i, y1 = j, x2 = i + x - 1, y2 = j + x - 1;
					if(s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] >= x * x) return true;
				}
				return false;
		};

		int l = 0, r = min(n, m) + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout <<l <<endl;
	}
	return 0;
}