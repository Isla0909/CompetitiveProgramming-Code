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

constexpr int N = 3e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 tr[N];

int lowbit(int x)
{
	return (x & -x);
}

void add(int x, int c)
{
	for(int i = x; i < N; i += lowbit(i))
		tr[i] += c;
}

i64 sum(int x)
{
	i64 res = 0;
	for(int i = x; i; i -= lowbit(i))
		res += tr[i];
	return res;
}

i64 rangeSum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<array<int, 3>> v(n);
	vector<int> b;
	for(int i = 0; i < n; i ++)
	{
		int x, y, p; cin >>x >>y >>p;
		v[i] = {x, y, p};
		b.push_back(y);
	}

	vector<array<int, 5>> query;
	for(int i = 1; i <= q; i ++)
	{
		int x1, y1, x2, y2; cin >>x1 >>y1 >>x2 >>y2;
		query.push_back({i, x1 - 1, y1, y2, -1});
		query.push_back({i, x2, y1, y2, 1});
		b.push_back(y1), b.push_back(y2);
	}

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	auto find = [&](int x) -> int
	{
		return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
	};

	sort(v.begin(), v.end());
	sort(query.begin(), query.end(), [&](const auto &a, const auto &b)
	{
		return a[1] < b[1];
	});

	vector<i64> ans(q + 1);
	for(int i = 0, j = -1; i < query.size(); i ++)
	{
		auto [id, x, l, r, f] = query[i];
		l = find(l), r = find(r);
		while(j + 1 < n && v[j + 1][0] <= x)
		{
			j ++;
			add(find(v[j][1]), v[j][2]);
		}
		ans[id] += f * rangeSum(l, r);
	}

	for(int i = 1; i <= q; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
