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
typedef pair<int,int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < (int)v.size(); i ++)
		cout << v[i] << " \n"[i == (int)v.size() - 1];
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
		int n, y; cin >>n >> y;
		vector<int> a(n + 1);
		vector<int> cnt(N + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i];
			cnt[a[i]] ++;
		}

		vector<int> pre(N + 1, 0);
		for(int i = 1; i <= N; i ++)
			pre[i] = pre[i - 1] + cnt[i];

		i64 ans = -inf;
		for(int x = 2; x <= N; x ++)
		{
			i64 s = 0; int tot = 0;
			for(int k = 1; k * x <= N + x; k ++)
			{
				int l = (k - 1) * x + 1, r = min(k * x, N);
				int c = pre[r] - pre[l - 1];
				s += 1LL * k * c;

				tot += min(cnt[k], c);
			}
			i64 res = s - 1LL * y * (n - tot);
			ans = max(ans, res);
		}

		i64 s = n;
		int tot = min(cnt[1], n);
		i64 res = s - 1LL * y * (n - tot);
		ans = max(ans, res);

		cout << ans << endl;
	}
	return 0;
}
