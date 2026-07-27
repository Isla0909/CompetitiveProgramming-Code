#pragma GCC optimize(2)
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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x0, y0, n, m; cin >>x0 >>y0 >>n >>m;
	vector<int> x(n + m + 1), y(n + m + 1);
	x[0] = x0, y[0] = y0;
	for(int i = 1; i <= n + m; i ++)
		cin >>x[i] >>y[i];

	auto get = [&](int i, int j) -> f64
	{
		int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
		if(x1 == x2)
		{
			for(int k = n + 1; k <= n + m; k ++)
				if(x[k] == x1 && y[k] > min(y1, y2) && y[k] < max(y1, y2)) return 1e18;
		}
		else
		{
			for(int k = n + 1; k <= n + m; k ++)
				if((y2 - y1) * (x[k] - x1) == (y[k] - y1) * (x2 - x1))
				{
					if(x[k] > min(x1, x2) && x[k] < max(x1, x2)) return 1e18;
				}
		}
		int dx = x1 - x2, dy = y1 - y2;
		return sqrtl(dx * dx + dy * dy);
	};

	vector<vector<f64>> g(n + 1, vector<f64>(n + 1, 1e18));
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			g[i][j] = g[j][i] = get(i, j);

	for(int i = 1; i <= n; i ++)
	{
		int dx = x[i] - x[0], dy = y[i] - y[0];
		g[i][0] = 2.l * sqrtl(dx * dx + dy * dy);
	}

	vector<f64> d(n + 1, 1e18);
	vector<bool> st(n + 1);
	d[1] = 0;

	for(int i = 0; i <= n; i ++)
	{
		int t = -1;
		for(int j = 0; j <= n; j ++)
			if(!st[j] && (t == -1 || d[j] < d[t]))
				t = j;
		st[t] = true;
		for(int j = 0; j <= n; j ++)
			d[j] = min(d[j], d[t] + g[t][j]);
	}
	cout <<fixed <<setprecision(0) <<d[0] <<endl;
	return 0;
}
