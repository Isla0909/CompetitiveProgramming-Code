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

	int n, k, m, c, d; cin >>n >>k >>m >>c >>d;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto check = [&](i64 x) -> bool
	{
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			cnt += (a[i] >= x ? 1 : 0);
		if(cnt >= k) return true;

		vector<int> f(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] >= x) continue;

			i64 up = a[i] + c + 1LL * d * min(m - 1, i - 1);
			if(up < x) continue;

			f[max(m, i)] ++;

			i64 down = a[i] + c;
			if(down >= x)
			{
				if(i + m <= n) f[i + m] --;
			}
			else
			{
				i64 delta = x - (a[i] + c);
				i64 pos;
				if(delta % d == 0) pos = delta / d - 1;
				else pos = delta / d;
				if(i + (m - 1 - pos) <= n) f[i + (m - 1 - pos)] --;
			}
		}

		for(int i = m; i <= n; i ++)
		{
			cnt += f[i];
			if(cnt >= k) return true;
		}
		return false;
	};

	i64 lo = -1, hi = 1e18;
	while(lo + 1 != hi)
	{
		i64 mid = lo + hi >> 1;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout <<max(0LL, lo) <<endl;
	return 0;
}