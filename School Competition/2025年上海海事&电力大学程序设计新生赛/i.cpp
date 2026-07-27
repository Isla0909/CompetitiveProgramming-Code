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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<pii> pos(n * m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
			{
				int x; cin >>x;
				pos[x] = {i, j};
			}

		i64 res = 0;
		int x1 = INF, y1 = INF, x2 = -INF, y2 = -INF;
		for(int k = 0; k < n * m; k ++)
		{
			auto [x, y] = pos[k];
			x1 = min(x1, x);
			y1 = min(y1, y);
			x2 = max(x2, x);
			y2 = max(y2, y);
			res += 1LL * (x1 + 1) * (n - 1 - x2 + 1) * (y1 + 1) * (m - 1 - y2 + 1);
		}
		cout <<res <<endl;
	}
	return 0;
}