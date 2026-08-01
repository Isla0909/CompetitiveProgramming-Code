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
typedef pair<i64, i64> pii;

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

	int n, L; cin >>n >>L;
	vector<i64> c(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>c[i];
		pre[i] = pre[i - 1] + c[i] + 1;
	}

	auto front = [&](pii &a, pii &b, i64 x)
	{
		auto [k1, b1] = a; auto [k2, b2] = b;
		return (i128)k1 * x + b1 >= (i128)k2 * x + b2;
	};

	vector<i64> f(n + 1, inf);
	f[0] = 0;
	deque<pii> q; q.emplace_back(0, 0);
	for(int i = 1; i <= n; i ++)
	{
		i64 x = pre[i] - L - 1;
		while(q.size() >= 2 && front(q[0], q[1], x)) q.pop_front();

		auto [k, b] = q.front();
		f[i] = k * x + b;
	}
	return 0;
}
