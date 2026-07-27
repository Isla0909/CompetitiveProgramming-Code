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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>b[i];

	int m = 3000;
	vector<i64> dp(m + 1), pre(m + 1), ndp(m + 1), npre(m + 1);
	dp[0] = 1;
	for(int j = 0; j <= m; j ++)
		pre[j] = (dp[j] + (j ? pre[j - 1] : 0)) % mod;
	
	for(int i = 1; i <= n; i ++)
	{
		fill(ndp.begin(), ndp.end(), 0LL);
		fill(npre.begin(), npre.end(), 0LL);
		for(int j = a[i]; j <= b[i]; j ++)
			ndp[j] = pre[j];
		
		for(int j = 0; j <= m; j ++)
			npre[j] = (ndp[j] + (j ? npre[j - 1] : 0)) % mod;


		dp = ndp;
		pre = npre;
	}
	i64 ans = 0;
	for(int j = 0; j <= m; j ++)
		ans = (ans + dp[j]) % mod;
	cout <<ans <<endl;
	return 0;
}
