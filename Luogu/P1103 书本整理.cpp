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

constexpr int N = 1e2 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int f[N][N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<array<int, 2>> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>a[i][0] >>a[i][1];

	sort(a.begin() + 1, a.end());

	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;

	for(int i = 1; i <= n; i ++)
	{
		int h = a[i][1];
		//选
		for(int j = 0; j <= i - 1; j ++)
			for(int k = 0; k <= m; k ++)
			{
				if(j) f[i][i][k] = min(f[i][i][k], f[i - 1][j][k] + abs(h -  a[j][1]));
				else f[i][i][k] = min(f[i][i][k], f[i - 1][0][k]);
			}
		//不选
		for(int j = 0; j <= i - 1; j ++)
			for(int k = 1; k <= m; k ++)
				f[i][j][k] = min(f[i][j][k], f[i - 1][j][k - 1]);
	}
	int ans = INF;
	for(int j = 1; j <= n; j ++)
		ans = min(ans, f[n][j][m]);
	cout <<ans <<endl;
	return 0;
}
