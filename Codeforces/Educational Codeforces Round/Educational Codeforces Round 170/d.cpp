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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> r(n);
	for(int i = 0; i < n; i ++) cin >>r[i];

	int cnt = 0;
	vector<int> diff(m + 1, 0);
	diff[1] = -INF;
	for(int i = 0; i < n; i ++)
	{
		if(!r[i])
		{
			cnt ++;
			auto f = diff;
			for(int j = 1; j <= m; j ++)
				f[j] += f[j - 1];
			vector<int> dp(m + 1);
			dp[0] = f[0];
			for(int j = 1; j <= m; j ++)
				dp[j] = max(f[j], f[j - 1]);
			diff[0] = dp[0];
			for(int j = 1; j <= m; j ++)
				diff[j] = dp[j] - dp[j - 1]; 
		}
		else if(r[i] > 0)
		{
			int l = r[i], r = cnt;
			if(l > r) continue;

			diff[l] ++;
			if(r + 1 <= m) diff[r + 1] --;
		}
		else
		{	
			//cnt - j >= -r[i];
			int left = 0, right = cnt + r[i];
			if(left > right) continue;

			diff[left] ++;
			if(right + 1 <= m) diff[right + 1] --;
		}
	}
	auto dp = diff;
	for(int i = 1; i <= m; i ++)
		dp[i] += dp[i - 1];
	cout <<*max_element(dp.begin(), dp.end()) <<endl;

	return 0;
}