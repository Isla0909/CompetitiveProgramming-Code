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

struct Fenwick
{
	#define lowbit(x) (x & -x)

	int n;
	vector<int> tr;

	Fenwick(int n)
	{
		this->n = n;
		tr.assign(n + 1, 0);
	}

	void add(int x, int c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	int sum(int x)
	{
		int res = 0;
		for(int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	int RangeSum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};

signed main()
{
	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<array<int, 3>> query(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int l, r; cin >>l >>r;
		query[i] = {i, l, r};
	}

	sort(query.begin() + 1, query.end(), [&](const auto &a, const auto &b)
	{
		return a[2] < b[2];
	});

	Fenwick bit(n);
	vector<int> ans(m + 1), last(n + 1, -1);
	for(int i = 1, j = 0; i <= m; i ++)
	{
		auto [id, l, r] = query[i];
		while(j + 1 <= r)
		{
			j ++;
			int c = a[j];
			if(last[c] != -1) bit.add(last[c], -1);

			last[c] = j;
			bit.add(j, 1);
		}
		ans[id] = bit.RangeSum(l, r);
	}
	for(int i = 1; i <= m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
