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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 quick_pow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;
		s = ' ' + s;
		vector f(n + 1, vector<int>(n + 1));
		for(int i = 1; i <= n; i ++) f[i][i] = 1;

		for(int len = 2; len <= n; len ++)
		{
			for(int i = 1; i + len - 1 <= n; i ++)
			{
				int l = i, r = i + len - 1;
				if(r == l + 1) f[l][r] = (s[l] == s[r]);
				else f[l][r] = f[l + 1][r - 1] & (s[l] == s[r]);
			}
		}

		vector<i64> cnt(n + 1), dp(n + 1);
		cnt[0] = 1, dp[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			i64 c = 0;
			for(int j = 1; j <= i; j ++)
			{
				if(!f[j][i]) continue;
				int len = i - j + 1;

				cnt[i] = (cnt[i] + cnt[j - 1]) % mod;
				dp[i] = (dp[i] + dp[j - 1] + 1LL * len * len % mod * cnt[j - 1] % mod) % mod;
			}
		}
		cout <<dp[n] <<endl;
	}
	return 0;
}
