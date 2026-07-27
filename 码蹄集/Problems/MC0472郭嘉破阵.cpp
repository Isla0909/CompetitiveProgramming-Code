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

	int n; cin >>n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>b[i];

	vector<i64> pre(n + 1);
	for(int i = 1; i <= n; i ++)
		pre[i] = (pre[i - 1] + b[i]) % mod;

	i64 ans = 0;
	for(int j = 0; j < 30; j ++)
	{
		i64 c = 0;
		i64 cnt[2] = {1, 0}, sum[2] = {0, 0};
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] >> j & 1) c ^= 1;

			int op = c ^ 1;

			ans = (ans + (1LL << j) * (pre[i] * cnt[op] % mod - sum[op] + mod) % mod) % mod;

			cnt[c] ++;
			sum[c] = (sum[c] + pre[i]) % mod;
		}
	}
	cout <<ans <<endl
;	return 0;
}
