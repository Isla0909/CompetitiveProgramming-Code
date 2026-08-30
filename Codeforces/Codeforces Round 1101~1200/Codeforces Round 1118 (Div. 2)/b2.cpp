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

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> a(n + 1), cnt(m + 1); i64 sum = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			sum += a[i];
			cnt[a[i]] ++;
		}

		vector<i64> suf(m + 2);
		for(int i = m; i >= 1; i --)
			suf[i] = suf[i + 1] + cnt[i];

		vector<i64> val(m + 1);
		for(int x = 1; x <= m; x ++)
		{
			val[x] = suf[x];
			if(2 * x <= m) val[x] += cnt[2 * x];
		}

		vector<i64> ans(m + 1);
		i64 len = 2;
		for(int k = 1; k <= m; k ++)
		{
			i64 res = 0;
			for(int x = 1; x <= m; x ++)
				res = max(res, val[x]);
			ans[k] = res;

			if(len >= m)
			{
				for(int j = k + 1; j <= m; j ++)
					ans[j] = sum;
				break;
			}

			i64 nlen = len << 1;
			for(int j = len; j < nlen && j <= m; j ++)
			{
				for(int x = 1; j * x <= m; x ++)
					val[x] += suf[j * x];
			}
			for(int x = 1; len * x <= m; x ++)
				val[x] -= cnt[len * x];
			for(int x = 1; nlen * x <= m; x ++)
				val[x] += cnt[nlen * x];
			len = nlen;
		}
		tell(1, ans);
	}
	return 0;
}
