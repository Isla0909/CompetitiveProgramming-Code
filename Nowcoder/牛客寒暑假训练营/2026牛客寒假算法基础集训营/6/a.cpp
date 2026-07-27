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
constexpr f64 eps = 1e-8;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

struct cxy
{
	i64 x, y;
	f64 d, delta;

	cxy(i64 x, i64 y, f64 d, f64 delta) : x(x), y(y), d(d), delta(delta) {}

	bool operator<(const cxy &W) const
	{
		return delta < W.delta;
	}
};

bool cmp(const cxy &a, const cxy &b)
{
	return a.d < b.d;
}

f64 get(i64 x, i64 y)
{
	if(y < 0) y = 0;
	return sqrtl(x * x + y * y);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w; cin >>n >>w;
	priority_queue<cxy> q;
	for(int i = 0; i < n; i ++)
	{
		i64 x, y; cin >>x >>y;
		f64 d = get(x, y);
		f64 delta = d - get(x, y - 1);
		q.emplace(x, y, d, delta);
	}

	for(int i = 0; i < w; i ++)
	{
		auto [x, y, d, delta] = q.top();
		//cout <<x <<" " <<y <<" " <<d <<" " <<delta <<endl;
		if(fabs(delta) < eps) break;
		q.pop();

		f64 nd = get(x, y - 1), ndelta = nd - get(x, y - 2);
		q.emplace(x, y - 1, nd, ndelta);
	}
	f64 ans = 0;
	while(q.size())
	{
		auto [x, y, d, delta] = q.top(); q.pop();
		ans += d;
	}
	cout <<fixed <<setprecision(12) <<ans <<endl;
	return 0;
}
