#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, x, y; cin >>n >>x >>y;
		vector<int> a(n + 1); unordered_map<int, int> cnt;
		int mmax = 0;
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			a[i] = x;
			cnt[x] ++;
			mmax = max(mmax, cnt[x]);
		}

		sort(a.begin() + 1, a.end());
		int k = 0, s = a[n];

		auto get = [&](int x) -> int//大于k的数的个数
		{
			int less = upper_bound(a.begin() + 1, a.end(), x) - (a.begin() + 1);
			return n - less;
		};

		i64 res = (n - mmax) * y;

		i64 ans = inf;
		for(int i = 1; i <= n; i ++)
		{
			int res = a[i] * x + get(a[i]) * y;
			
			ans = min(ans, res);
		}

		cout <<min(ans, res) <<endl;
	}
	return 0;
}