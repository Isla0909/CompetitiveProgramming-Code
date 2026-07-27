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

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int trans(int a, int b)
{
	int res = b;
	for(int i = 1; i < a; i ++)
		res += mon[i];
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, k; cin >>n >>m >>k;
	vector<pii> v(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int a, b, c; cin >>a >>b >>c;
		v[i] = {trans(a, b), c};
	}
	sort(v.begin() + 1, v.end());
	vector f(n + 1, vector<int>(m + 1, INF));
	f[0][0] = -INF;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			if(j - v[i].se >= 0 && v[i].ff - f[i - 1][j - v[i].se] >= k)
				f[i][j] = min(f[i][j], v[i].ff);
		}
	}
	for(int j = m; j >= 0; j --)
		if(f[n][j] < INF)
		{
			cout <<j <<endl;
			break;
		}
	return 0;
}