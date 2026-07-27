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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 676767677;

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

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> b(n + 1), cnt(m), pre(m + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>b[i];
			cnt[b[i]] ++;
		}

		for(int i = 1; i <= m; i ++)
			pre[i] = pre[i - 1] + cnt[i - 1];

		i64 ans = 1; bool f = 1;
		for(int i = 1; i <= n && f; i ++)
		{
			int k = b[i];
			if(!k) continue;

			int d = INF;
			if(i - 1 >= 1) d = min(d, b[i - 1]);
			if(i + 1 <= n) d = min(d, b[i + 1]);

			if(d >= k) f = 0;

			if(d == k - 1) ans = ans * pre[k] % mod;
			else ans = ans * (pre[k] - pre[k - 1]) % mod;
		}
		cout <<(f ? ans : 0) <<endl;
	}
	return 0;
}
