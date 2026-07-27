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

void tell(int l, vector<i64> &v)
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

	int m, s, t; cin >>m >>s >>t;
	int p = m / 10, q = m % 10;
	if(t <= p)
	{
		if(t * 60 >= s) cout <<"Yes" <<endl <<(s + 59) / 60 <<endl;
		else cout <<"No" <<endl <<60 * t <<endl;
	}
	else
	{
		t -= p; m = q;
		vector<i64> dp(61, -inf);
		dp[q] = 60 * p; bool f = 0;
		for(int i = 1; i <= t; i ++)
		{
			vector<i64> ndp(61, -inf);
			for(int j = 0; j <= 60; j ++)
			{
				if(dp[j] == -inf) continue;

				ndp[j] = max(ndp[j], dp[j] + 17);
				if(j >= 10) ndp[j - 10] = max(ndp[j - 10], dp[j] + 60);
				if(j + 4 <= 60) ndp[j + 4] = max(ndp[j + 4], dp[j]);
			}
			dp = ndp;
			for(int j = 0; j <= 60; j ++)
				if(dp[j] >= s)
				{
					cout <<"Yes" <<endl;
					cout <<i + p <<endl;
					f = 1;
					break;
				}
			if(f) break;
		}
		if(!f) 
		{
			cout <<"No" <<endl;
			cout <<*max_element(dp.begin(), dp.end()) <<endl;
		}
	}
	return 0;
}
