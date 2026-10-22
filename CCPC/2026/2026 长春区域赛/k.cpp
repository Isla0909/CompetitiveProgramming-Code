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
		this -> n = n;
		tr.assign(n + 1, {});
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
};

struct seg
{
	int l, r, id;
	seg() {}
	seg(int l, int r, int id) : l(l), r(r), id(id) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;; cin >>n >>m >>q;
	vector<pii> a(m + 1);
	for(int i = 1; i <= m; i ++)
		cin >>a[i].ff >>a[i].se;

	vector<vector<pii>> query(m + 1);
	for(int i = 0; i < q; i ++)
	{
		int l, r; cin >>l >>r;
		query[r].emplace_back(l, i);
	}

	Fenwick bit(m);
	deque<seg> d;
	vector<int> ans(q);

	for(int i = 1; i <= m; i ++)
	{
		auto [op, x] = a[i];
		if(op == 0)
		{
			while(d.size() && d.front().r <= x)
			{
				bit.add(d.front().id, -1);
				d.pop_front();
			}
			if(d.size() && d.front().l <= x)
				d.front().l = x + 1;
			d.emplace_front(1, x, i);
		}
		else
		{
			while(d.size() && d.back().l >= x)
			{
				bit.add(d.back().id, -1);
				d.pop_back();
			}
			if(d.size() && d.back().r >= x)
				d.back().r = x - 1;
			d.emplace_back(x, n, i);
		}
		bit.add(i, 1);

		for(auto [l, id] : query[i])
			ans[id] = bit.sum(i) - bit.sum(l - 1);
	}
	for(auto x : ans)
		cout <<x <<endl;
	return 0;
}
