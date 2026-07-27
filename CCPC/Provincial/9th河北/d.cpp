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
	cin.tie(0) -> sync_with_stdio(false);

	int n; ll k; cin >>n >>k;
	vector<int> a(n + 1); vector<ll> pre(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	sort(a.begin() + 1, a.end());

	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];

	auto check = [&](int x) -> bool
	{
		ll cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			// int c = upper_bound(a.begin() + 1, a.end(), a[i] - x - 1) - a.begin() - 1;
			int l = 0, r = i;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(a[mid] <= a[i] - x - 1) l = mid;
				else r = mid;
			}
			cnt += i - l - 1;
            if(cnt >= k) return true;
		}
		return cnt >= k;
	};

	int l = -1, r = 1e8;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}

	ll ans = 0; int x = r - 1;
	ll cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		int l = 0, r = i;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(a[mid] <= a[i] - x - 1) l = mid;
			else r = mid;
		}
		int c = l;
		int v = i - c - 1; cnt += v;
		ans += 1LL * v * a[i] - (pre[i - 1] - pre[c]);
	}
	cout <<ans + 1LL * (k - cnt) * r <<endl;
	return 0;
}