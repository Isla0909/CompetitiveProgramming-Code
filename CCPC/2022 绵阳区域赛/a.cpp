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

i64 f[N][11][11];	

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector<i64> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>b[i];

	sort(a.begin() + 1, a.end(), greater<>());
	sort(b.begin() + 1, b.end(), greater<>());

	for(int x = 2 * n; x >= 1; x --)
	{
		int ta = x / 2, tb = (x - 1) / 2;
		for(int i = 0; i <= k; i ++)
			for(int j = 0; j <= k; j ++)
			{
				int p = i + (tb - j), q = j + (ta - i);
				if(i > ta || j > tb) continue;
				if(p < 0 || p > n || q < 0 || q > n) continue;

				if((i == k || p == n) && (j == k || q == n)) continue;

				if(x & 1)
				{
					f[x][i][j] = -inf;
					if(i < k && p < n) f[x][i][j] = max(f[x][i][j], a[p + 1] + f[x + 1][i + 1][j]);
					if(q < n) f[x][i][j] = max(f[x][i][j], f[x + 1][i][j]);
				}
				else
				{
					f[x][i][j] = inf;
					if(j < k && q < n) f[x][i][j] = min(f[x][i][j], -b[q + 1] + f[x + 1][i][j + 1]);
					if(p < n) f[x][i][j] = min(f[x][i][j], f[x + 1][i][j]);
				}
			}
	}
	cout <<f[1][0][0] <<endl;
	return 0;
}
