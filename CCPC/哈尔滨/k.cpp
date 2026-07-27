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
#define int long long
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	int w;
	int l;
	int r;
	int d;
}s[N];

bool cmp(cxy &a, cxy &b)
{
	return a.w > b.w;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >>s[i].w >>s[i].l >>s[i].r;
		s[i].d = s[i].r - s[i].l;

		sum += s[i].w * s[i].l, cnt += s[i].l;
	}

	sort(s + 1, s + 1 + n, cmp);

	vector<int> pre_sum(n + 1), pre_cnt(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		pre_sum[i] = pre_sum[i - 1] + s[i].w * s[i].d;
		pre_cnt[i] = pre_cnt[i - 1] + s[i].d;
	}

	int ans = -1;
	for(int i = 1; i <= n; i ++)
	{
		int less = m - (cnt - s[i].l);

		int l = 0, r = n + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(pre_cnt[mid] <= less) l = mid;
			else r = mid;
		}

		int res;
		if(l >= i - 1)
			res = sum - s[i].l * s[i].w + pre_sum[i - 1] + (less - pre_cnt[i - 1]) * s[i].w;
		else
			res = sum - s[i].l * s[i].w + pre_sum[l] + (less - pre_cnt[l]) * s[l + 1].w;

		ans = max(ans, res);
	}
	cout <<ans <<endl;
	return 0;
}