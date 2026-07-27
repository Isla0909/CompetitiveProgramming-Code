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
	vector<int> ban(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		string s; cin >>s;
		for(int j = 0; j < m; j ++)
			if(s[j] == 'H') ban[i] += (1 << j);
	}

	vector<int> state, cnt;
	for(int s = 0; s < (1 << m); s ++)
	{
		if(s & (s >> 1) || s & (s >> 2)) continue;

		state.push_back(s);
		cnt.push_back(__builtin_popcount(s));
	}

	int len = state.size();
	vector<vector<int>> dp(len, vector<int>(len, -INF));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		auto ndp = dp;
		for(int a = 0; a < len; a ++)
		{
			int x = state[a];
			if(x & ban[i]) continue;

			for(int b = 0; b < len; b ++)
			{
				int y = state[b];
				if(x & y) continue;

				for(int c = 0; c < len; c ++)
				{
					int z = state[c];
					if(dp[b][c] == -INF || x & z) continue;

					ndp[a][b] = max(ndp[a][b], dp[b][c] + cnt[a]);
				}
			}
		}
		swap(dp, ndp);
	}
	int ans = 0;
	for(int i = 0; i < len; i ++)
		for(int j = 0; j < len; j ++)
			ans = max(ans, dp[i][j]);
	cout <<ans <<endl;	
	return 0;
}
