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
constexpr f64 eps = 1e-6;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

struct Point
{
    f64 x, y;

    Point() : x(0), y(0) {}
    Point(f64 x, f64 y) : x(x), y(y) {}
};

f64 cross(f64 x1, f64 y1, f64 x2, f64 y2)
{
    return x1 * y2 - x2 * y1;
}

f64 area(Point a, Point b, Point c)// ab × ac
{
    return cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x1, y1, x2, y2; cin >>x1 >>y1 >>x2 >>y2;
	Point a(x1, y1), b(x2, y2);

	if(y1 == y2)
	{
		int dx = abs(x1 - x2), h = abs(y1);
		if(dx * h == 4) cout <<1 <<endl;
		else cout <<"no answer" <<endl;
	}
	else cout <<fixed <<setprecision(8) <<(cross(x1, y1, x2, y2) - 4) / (y2 - y1) <<endl;
	return 0;
}
