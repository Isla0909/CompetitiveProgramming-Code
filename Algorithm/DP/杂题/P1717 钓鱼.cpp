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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m; m *= 60;
	vector<int> w(n + 1), d(n + 1), t(n);
	for(int i = 1; i <= n; i ++) cin >>w[i];
	for(int i = 1; i <= n; i ++) cin >>d[i];
	for(int i = 1; i < n; i ++) cin >>t[i], t[i] *= 5;

	vector f(n + 1, vector<int>(m + 1, -INF));
	f[0][0] = 0, f[1][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= t[i - 1]; j --)
		{
			//不钓鱼
			f[i][j] = f[i - 1][j - t[i - 1]];
			//钓鱼
			int temp = 0;
			for(int k = 5; k <= j; k += 5)
			{
				if(j - t[i - 1] - k < 0) break;
				f[i][j] = max(f[i][j], f[i - 1][j - t[i - 1] - k] + w[i] * (k / 5) - temp);
				temp += (k / 5) * d[i];
			}
		}	
	}
	int ans = -INF;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= m; j ++)
			ans = max(ans, f[i][j]);
	cout <<ans <<endl;
	return 0;
}