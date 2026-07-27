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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<int>(m + 1));
	vector pre(n + 1, vector<i64>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			cin >>g[i][j];
			pre[i][j] = pre[i][j - 1] + g[i][j];
		}

	vector<i64> dp(m + 1, -inf), ndp(m + 1, -inf);
	dp[1] = 0;
	for(int i = 1; i <= n; i ++)
	{
		fill(ndp.begin(), ndp.end(), -inf);

		int j = 1;
		while(j <= m)
		{
			if(g[i][j] == -1)
			{
				j ++;
				continue;
			}

			int l = j; i64 M = -inf;
			while(j <= m && g[i][j] != -1)
			{
				M = max(M, dp[j]);
				j ++;
			}
			for(int k = l; k < j; k ++)
				ndp[k] = max(ndp[k], M + pre[i][j - 1] - pre[i][l - 1]);
		}
		swap(dp, ndp);
	}
	cout <<(dp[m] < 0 ? -1 : dp[m]) <<endl;
	return 0;
}
