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

	auto dis = [&](int x1, int x2, int y1, int y2) -> i64
	{
		int dx = x1 - x2, dy = y1 - y2;
		return 1LL * dx * dx + 1LL * dy * dy;
	};

	int x1, y1, x2, y2, x3, y3; cin >>x1 >>y1 >>x2 >>y2 >>x3 >>y3;
	i64 d1 = dis(x1, y1, x2, y2), d2 = dis(x1, y1, x3, y3), d3 = (x2, y2, x3, y3);
	if(d1 == d2 && d2 == d3) cout <<"YES" <<endl;
	else cout <<"NO" <<endl;

	return 0;
}
