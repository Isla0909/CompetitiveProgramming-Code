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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, M = 1e4 + 1, INF = 0x3f3f3f3f, mod = 1e9 + 7;
using bit = bitset<M + 1>;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> a(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>a[i];
			a[i] = min(a[i], m + 1);
		}	
		vector <pair<int, bit>> dp;//前i个数部分数乘法还未求和的和的集合   
		dp.emplace_back(a[0], 1);

		for(int i = 1; i < n; i ++)
		{
			if(a[i] == 0)
			{
				bit b = {};
				for(auto &[x, y] : dp)
				{
					b |= y;
					b |= y << x;//y + x
				}
				dp = {{0, b}};
			}
			else
			{
				bit b = {};
				for(auto &[x, y] : dp)
				{
					b |= y << x;
					x *= a[i];
					x = min(x, m + 1);
				}
				while(dp.size() >= 2 && dp[dp.size() - 2].ff == m + 1)
				{
					auto [_, y] = dp.back();
					dp.pop_back();
					dp.back().se |= y;
				}

				int j = 0;
				while(j < dp.size() && dp[j].ff < a[i]) j ++;

				if(j < dp.size() && dp[j].ff == a[i])
					dp[j].se |= b;
				else
					dp.insert(dp.begin() + j, {a[i], b});
			}
		}
		bool f = 0;
		for(auto &[x, y] : dp)
			if(x <= m && y[m - x])
			{
				f = 1;
				break;
			}
		cout <<((f) ? "YES" : "NO") <<endl;
	}
	return 0;
}