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

	int n; cin >>n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>b[i];

	auto top = [&](pair<i64, i64> &a, pair<i64, i64> &b, int x) -> bool
	{
		auto [k1, b1] = a; auto [k2, b2] = b;
		return k1 * x + b1 >= k2 * x + b2;
	};

	auto back = [&](pair<i64, i64> &a, pair<i64, i64> &b, pair<i64, i64> &c) -> bool
	{
		auto [k1, b1] = a; auto [k2, b2] = b; auto [k3, b3] = c;
		return (i128)(b2 - b1) * (k2 - k3) >= (i128)(b3 - b2) * (k1 - k2);
	};

	vector<i64> f(n + 1, inf);
	f[1] = 0;
	deque<pair<i64, i64>> q; q.emplace_back(b[1], 0);
	for(int i = 2; i <= n; i ++)
	{
		while(q.size() >= 2 && top(q[0], q[1], a[i])) q.pop_front();

		auto [k, m] = q.front();
		f[i] = k * a[i] + m;
		
		pair<i64, i64> now = {b[i], f[i]};
		while(q.size() >= 2 && back(q[q.size() - 2], q.back(), now)) q.pop_back();

		q.emplace_back(now);
	}
	cout <<f[n] <<endl;
	return 0;
}
