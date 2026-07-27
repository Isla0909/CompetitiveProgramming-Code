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
constexpr long double eps = 1e-16L;

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
		int x1, y1, x2, y2; cin >>x1 >>y1 >>x2 >>y2;
		int x3, y3, x4, y4; cin >>x3 >>y3 >>x4 >>y4;

		long double dx = x2 - x1, dy = y2 - y1;
		long double s1 = sqrtl(dx * dx + dy * dy);
		long double cos1 = dx / s1, sin1 = dy / s1;

		dx = x4 - x3, dy = y4 - y3;
		long double s2 = sqrtl(dx * dx + dy * dy);
		long double cos2 = dx / s2, sin2 = dy / s2;

		auto f = [&](long double t) -> long double
		{
			long double a, b, c, d;

			if(t >= s1) a = x2, b = y2;
			else a = 1.L * x1 + t * cos1, b = 1.L * y1 + t * sin1;

			if(t >= s2) c = x4, d = y4;
			else c = 1.L * x3 + t * cos2, d = 1.L * y3 + t * sin2;

			long double dx = a - c, dy = b - d;
			return dx * dx + dy * dy;
		};	
		long double ans = 1e18;
		long double l = 0.L, r = min(s1, s2);
		while(r - l > eps)
		{
			long double mid1 = l + (r - l) / 3;
			long double mid2 = r - (r - l) / 3;
			if(f(mid1) > f(mid2)) l = mid1;
			else r = mid2;
		}
		ans = min(ans, f(l));

		l = min(s1, s2), r = max(s1, s2);
		while(r - l > eps)
		{
			long double mid1 = l + (r - l) / 3;
			long double mid2 = r - (r - l) / 3;
			if(f(mid1) > f(mid2)) l = mid1;
			else r = mid2;
		}
		ans = min(ans, f(l));
		cout <<fixed <<setprecision(15) <<sqrtl(ans) <<endl;
	}
	return 0;
}
