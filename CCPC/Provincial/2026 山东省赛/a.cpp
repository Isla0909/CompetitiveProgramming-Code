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

	int n, m; cin >>n >>m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>a[i][j];

	if(n > m)
	{
		vector<vector<int>> b(m + 1, vector<int>(n + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				b[j][i] = a[i][j];

		swap(a, b);
		swap(n, m);
	}

	i64 ans = -inf;
	vector<i64> pre(m + 1);
	for(int l = 1; l <= n; l ++)
	{
		fill(pre.begin(), pre.end(), 0LL);

		for(int r = l; r <= n; r ++)
		{
			for(int j = 1; j <= m; j ++)
				pre[j] += a[r][j];

			i64 res = 0;
			for(int j = 1; j <= m; j ++)
			{
				if(res < 0) res = 0;
				res += pre[j];
				ans = max(ans, res);
			}
		}
	}
	cout <<ans <<endl;
	return 0;
}
