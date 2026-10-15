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

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector<pair<i64, i64>> seg{{0, 0}};
		for(int i = 0; i < n; i ++)
		{
			i64 l, r; cin >>l >>r;
			seg.emplace_back(l, r);
		}
		vector<i64> pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			auto [l, r] = seg[i];
			pre[i] = pre[i - 1] + r - l + 1;
		}

		if(!k)
		{
			cout <<inf <<endl;
			continue;
		}

		auto get = [&](i64 x) -> i64
		{
			int l = 0, r = n + 1;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(seg[mid].se <= x) l = mid;
				else r = mid;
			}
			if(l == n) return pre[n];
			return pre[l] + max(0LL, x - seg[l + 1].ff + 1);
		};

		auto calc = [&](i64 s) -> i64
		{
			return get(s + m - 1) - get(s - 1);
		};

		i64 ans = -1;
		for(int i = 1; i <= n; i ++)
		{
			if(calc(seg[i].ff) >= k)
			{
				ans = seg[i].ff;
				break;
			}
		}

		if(ans == -1)
		{
			cout <<-1 <<endl;
			continue;
		}

		i64 l = ans - 1, r = seg[n].se + 1;
		while(l + 1 != r)
		{
			i64 mid = l + r >> 1;
			if(calc(mid) >= k) l = mid;
			else r = mid;
		}
		cout <<l <<endl;
	}
	return 0;
}
