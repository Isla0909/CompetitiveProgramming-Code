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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		i64 x1, y1, x2, y2, x3, y3, x4, y4; cin >>x1 >>y1 >>x2 >>y2 >>x3 >>y3 >>x4 >>y4;
		double mx1 = 1.0 * (x1 + x2) / 2, my1 = 1.0 * (y1 + y2) / 2;
		double mx2 = 1.0 * (x3 + x4) / 2, my2 = 1.0 * (y3 + y4) / 2;

		double d1 = fabs(mx1 - mx2), d2 = fabs(my1 - my2);
		i64 ans = min(d1, d2) * 2 + fabs(d1 - d2) * 2;
		cout <<ans <<endl;
	}
	return 0;
}