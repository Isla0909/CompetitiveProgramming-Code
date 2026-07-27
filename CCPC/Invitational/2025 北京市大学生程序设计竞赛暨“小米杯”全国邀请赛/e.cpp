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
constexpr f64 eps = 1e-9;

struct Point
{
	f64 x, y;
	Point(f64 x = 0, f64 y = 0) : x(x), y(y) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<Point> v;
		for(int i = 0; i < n; i ++)
		{
			int x, y; cin >>x >>y;
			v.emplace_back(x, y);
		}
		int a, b, c; cin >>a >>b >>c;
		if(b == 0)
		{
			auto get = [&](f64 y) -> f64
			{
				return (-b * y - c) / a;
			};

			auto calc = [](Point a, Point b)
			{
				f64 dx = a.x - b.x, dy = a.y - b.y;
				return dx * dx + dy * dy;
			};

			auto f = [&](f64 y) -> f64
			{
				f64 x = get(y);
				f64 res = 0;
				Point c(x, y);
				for(int i = 0; i < n; i ++)
					res = max(res, calc(v[i], c));
				return res;
			};

			f64 l = -1e4, r = 1e4;
			while(r - l > eps)
			{
				f64 mid1 = l + (r - l) / 3;
				f64 mid2 = r - (r - l) / 3;
				if(f(mid1) < f(mid2)) r = mid2;
				else l = mid1;
			}
			cout <<fixed <<setprecision(12) <<sqrtl(f(l)) <<endl;
		}
		else
		{
			auto get = [&](f64 x) -> f64
			{
				return (-a * x - c) / b;
			};

			auto calc = [](Point a, Point b)
			{
				f64 dx = a.x - b.x, dy = a.y - b.y;
				return dx * dx + dy * dy;
			};

			auto f = [&](f64 x) -> f64
			{
				f64 y = get(x);
				f64 res = 0;
				Point c(x, y);
				for(int i = 0; i < n; i ++)
					res = max(res, calc(v[i], c));
				return res;
			};

			f64 l = -1e4, r = 1e4;
			while(r - l > eps)
			{
				f64 mid1 = l + (r - l) / 3;
				f64 mid2 = r - (r - l) / 3;
				if(f(mid1) < f(mid2)) r = mid2;
				else l = mid1;
			}
			cout <<fixed <<setprecision(12) <<sqrtl(f(l)) <<endl;
		}
	}
	return 0;
}