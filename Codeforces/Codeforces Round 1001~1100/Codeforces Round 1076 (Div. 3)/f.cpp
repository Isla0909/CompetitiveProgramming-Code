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
		int n, sx, sy, ex, ey; cin >>n >>sx >>sy >>ex >>ey;
		vector<array<int, 2>> v(n);
		for(int i = 0; i < n; i ++) cin >>v[i][0];
		for(int i = 0; i < n; i ++) cin >>v[i][1];

		sort(v.begin(), v.end(), [&](auto a, auto b)
		{
			if(a[0] != b[0]) return a[0] < b[0];
			return a[1] < b[1];
		});

		vector<pii> a; int pre = sx;
		a.emplace_back(sy, sy);
		int lo = -1, hi = -1;
		for(int i = 0; i < v.size(); i ++)
		{
			auto [x, y] = v[i];
			if(x != pre)
			{
				if(lo != -1 && hi != -1) a.emplace_back(lo, hi);
				lo = hi = y;
			}
			else hi = y;
			pre = x;
		}
		a.emplace_back(lo, hi), a.emplace_back(ey, ey);

		// for(auto [lo, hi] : a)
		// 	cout <<lo <<" " <<hi <<endl;
		// cout <<endl;

		int m = a.size();
		vector<array<i64, 2>> f(m, {inf, inf});
		f[0][0] = f[0][1] = 0;

		auto calc = [&](int s, int l, int r, int e) -> i64
		{
			if(s >= l && s <= r) return (r - l) * 2 - abs(s - e);
			if(s < l)
			{
				if(e == l) return (r - l) * 2 + l - s;
				return r - s; 
			}
			if(s > r)
			{
				if(e == l) return s - l;
				return (r - l) * 2 + s - e;
			}
		};

		for(int i = 1; i < m; i ++)
		{
			auto [l1, h1] = a[i - 1]; auto [l2, h2] = a[i];
			f[i][1] = min(f[i][1], min(f[i - 1][0] + calc(l1, l2, h2, h2), f[i - 1][1] + calc(h1, l2, h2, h2)));
			f[i][0] = min(f[i][0], min(f[i - 1][0] + calc(l1, l2, h2, l2), f[i - 1][1] + calc(h1, l2, h2, l2)));
		}
		cout <<ex - sx + min(f[m - 1][1], f[m - 1][0]) <<endl;
	}
	return 0;
}
