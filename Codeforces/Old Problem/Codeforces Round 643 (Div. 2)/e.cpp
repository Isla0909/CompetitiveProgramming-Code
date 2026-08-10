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

	int n, A, R, M; cin >>n >>A >>R >>M;
	M = min(M, A + R);

	vector<int> h(n + 1);
	for(int i = 1; i <= n; i ++) cin >>h[i];

	auto f = [&](int x) -> i64
	{
		i64 s1 = 0, s2 = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(h[i] < x) s1 += x - h[i];
			if(h[i] > x) s2 += h[i] - x;
		}
		i64 c = min(s1, s2);
		s1 -= c, s2 -= c;
		return c * M + A * s1 + R * s2;
	};

	int l = 0, r = 1e9;
	while(r - l > 3)
	{
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if(f(mid1) <= f(mid2)) r = mid2;
		else l = mid1;
	}
	i64 ans = inf;
	for(int i = l; i <= r; i ++)
		ans = min(ans, f(i));
	cout <<ans <<endl;
	return 0;
}
