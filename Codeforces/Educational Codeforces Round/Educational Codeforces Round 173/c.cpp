#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		int x = 0;
		while(x < n && abs(a[x]) == 1) x ++;

		vector<int> ans;
		int min_sum = 0, max_sum = 0, min_ans = 0, max_ans = 0;
		for(int i = 0; i < x; i ++)
		{
			min_sum = min(0, min_sum) + a[i], min_ans = min(min_ans, min_sum);
			max_sum = max(0, max_sum) + a[i], max_ans = max(max_ans, max_sum);
		}	

		for(int i = min_ans; i <= max_ans; i ++)
			ans.push_back(i);

		min_sum = 0, max_sum = 0, min_ans = 0, max_ans = 0;
		for(int i = x + 1; i < n; i ++)
		{
			min_sum = min(0, min_sum) + a[i], min_ans = min(min_ans, min_sum);
			max_sum = max(0, max_sum) + a[i], max_ans = max(max_ans, max_sum);
		}

		for(int i = min_ans; i <= max_ans; i ++)
			ans.push_back(i);

		int lmin = 0, lmax = 0, rmin = 0, rmax = 0;
		int s = 0;
		for(int i = x - 1; i >= 0; i --)
		{
			s += a[i];

			lmin = min(lmin, s);
			lmax = max(lmax, s);
		}
		s = 0;
		for(int i = x + 1; i < n; i ++)
		{
			s += a[i];

			rmin = min(rmin, s);
			rmax = max(rmax, s);
		}
		x = (x == n) ? 0 : a[x];
		for(int i = lmin + rmin + x; i <= lmax + rmax + x; i ++)
			ans.push_back(i);

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		cout <<ans.size() <<endl;
		for(int i = 0; i < ans.size(); i ++)
			cout <<ans[i] <<" \n"[i == ans.size() - 1];
	}
	return 0;
}