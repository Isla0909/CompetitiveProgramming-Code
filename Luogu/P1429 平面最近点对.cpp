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

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};

i64 dis(Point &a, Point &b)
{
	auto [x1, y1] = a; auto [x2, y2] = b;
	i64 dx = x1 - x2, dy = y1 - y2;
	return dx * dx + dy * dy;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<Point> a(n), tmp(n), q(n);
	for(int i = 0; i < n; i ++)
		cin >>a[i].x >>a[i].y;

	sort(a.begin(), a.end(), [&](auto &a, auto &b)
	{
		if(a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});

	auto solve = [&](this auto &&self, int l, int r) -> i64
	{
		if(r - l + 1 <= 4)
		{
			i64 ans = inf;
			for(int i = l; i <= r; i ++)
				for(int j = i + 1; j <= r; j ++)
					ans = min(ans, dis(a[i], a[j]));
			sort(a.begin() + l, a.begin() + r + 1, [&](auto &a, auto &b)
			{
				return a.y < b.y;
			});
			return ans;
		}

		int mid = l + r >> 1;
		int midx = a[mid].x;

		i64 ans = min(self(l, mid), self(mid + 1, r));

		int i = l, j = mid + 1, k = l;
		while(i <= mid && j <= r)
		{
			if(a[i].y < a[j].y) tmp[k ++] = a[i ++];
			else tmp[k ++] = a[j ++];
		}
		while(i <= mid) tmp[k ++] = a[i ++];
		while(j <= r) tmp[k ++] = a[j ++];

		for(int i = l; i <= r; i ++)
			a[i] = tmp[i];

		int cnt = 0;
		for(int i = l; i <= r; i ++)
		{
			i64 dx = a[i].x - midx;
			if(dx * dx < ans) q[cnt ++] = a[i];
		}
		//q 天然已经按 y 排序
		for(int i = 0; i < cnt; i ++)
			for(int j = i + 1; j < cnt; j ++)
			{
				i64 dy = q[j].y - q[i].y;

				if(dy * dy >= ans) break;
				ans = min(ans, dis(q[i], q[j]));
			}
		return ans;
	};
	cout <<solve(0, n - 1) <<endl;	
	return 0;
}
