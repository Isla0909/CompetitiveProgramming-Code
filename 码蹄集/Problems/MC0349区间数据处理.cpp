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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int tr[N];

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int c)
{
	for(int i = x; i < N; i += lowbit(i))
		tr[i] += c;
}

int sum(int x)
{
	int res = 0;
	for(int i = x; i; i -= lowbit(i))
		res += tr[i];
	return res;
}

int rangeSum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto get = [&](int pos, int x) -> i64
	{
		return 100000LL * pos + x;
	};

	vector<array<int, 3>> v(q + 1);
	vector<vector<int>> vec(n + 1);
	vector<i64> b;
	for(int i = 1; i <= q; i ++)
	{
		int l, r, x; cin >>l >>r >>x;
		x ++;
		v[i][0] = l, v[i][1] = r, v[i][2] = x;
		vec[l - 1].push_back(x);
		vec[r].push_back(x);

		b.push_back(get(l - 1, x)), b.push_back(get(r, x));
	}

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	auto find = [&](i64 x) -> int
	{
		return lower_bound(b.begin(), b.end(), x) - b.begin();
	};

	vector<int> val(3 * q + 1);

	for(int i = 1; i <= n; i ++)
	{
		add(a[i] + 1, 1);
		if(vec[i].empty()) continue;
		//sort(vec[i].begin(), vec[i].end());
		//vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
		for(auto c : vec[i])
			val[find(get(i, c))] = i - sum(c - 1);
	}

	for(int i = 1; i <= q; i ++)
	{
		auto [l, r, x] = v[i];
		cout <<val[find(get(r, x))] - val[find(get(l - 1, x))] <<endl;
	}

	return 0;
}
