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

	freopen("glove.in", "r", stdin);
	freopen("glove.out", "w", stdout);

	int n; cin >>n;
	vector<i64> a(n + 1), dis(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		dis[i] = dis[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		i64 x; cin >>x;
		pre[i] = pre[i - 1] + x;
	}

	int q; cin >>q;
	while(q --)
	{
		int pos, k; cin >>pos >>k;

		auto check = [&](int x) -> bool
		{
			return abs(a[x] - pos) > abs(a[x + k] - pos);
		};

		int l = 0, r = n - k + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		int L = r, R = L + k - 1;
		int t = upper_bound(a.begin() + L, a.begin() + R + 1, pos) - a.begin() - 1;

		i64 res = 0;
		res += 1LL * pos * (t - L + 1) - (dis[t] - dis[L - 1]);
		res += dis[R] - dis[t] - 1LL * pos * (R - t);
		cout <<pre[R] - pre[L - 1] - res <<endl;
	}
	return 0;
}
