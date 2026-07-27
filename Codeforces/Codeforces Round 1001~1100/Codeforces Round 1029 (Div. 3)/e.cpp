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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		vector<int> cnt1(n + 1), cnt2(n + 1), cnt3(n + 1), cnt4(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x = a[i], y = b[i];
			if(i & 1) cnt1[x] ++, cnt3[y] ++;
			else cnt2[x] ++, cnt4[y] ++;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++)
			ans += min(cnt1[i] + cnt4[i], cnt2[i] + cnt3[i]);
		int res = ans;
		for(int i = n; i >= 1; i --)
		{
			int x = a[i], y = b[i];
			if(i & 1)
			{
				res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				cnt1[x] --;
				res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

				x = y;
				res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				cnt3[x] --;
				res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

				if(i + 1 <= n)
				{
					x = a[i + 1];
					res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
					cnt1[x] ++;
					res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

					x = b[i + 1];
					res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
					cnt3[x] ++;
					res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				}
			}
			else
			{
				res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				cnt2[x] --;
				res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

				x = y;
				res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				cnt4[x] --;
				res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

				if(i + 1 <= n)
				{
					x = a[i + 1];
					res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
					cnt2[x] ++;
					res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);

					x = b[i + 1];
					res -= min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
					cnt4[x] ++;
					res += min(cnt1[x] + cnt4[x], cnt2[x] + cnt3[x]);
				}
			}
			for(int i = 1; i <= n; i ++)
			{
				cout <<cnt1[i] <<" " <<cnt2[i] <<" " <<cnt3[i] <<" " <<cnt4[i] <<endl;
			}
			cout <<endl;
			ans = max(res, ans);
		}
		cout <<ans <<endl;
	}
	return 0;
}