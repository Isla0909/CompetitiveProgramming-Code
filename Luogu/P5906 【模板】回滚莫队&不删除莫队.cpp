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
	vector<int> a(n + 1), b;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 1; i <= n; i ++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();


	int m; cin >>m;
	vector<array<int, 3>> query(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int l, r; cin >>l >>r;
		query[i] = {l, r, i};
	}

	int len = n / min(n, (int)sqrt(m));
	vector<int> bel(n + 1);
	for(int i = 1; i <= n; i ++)
		bel[i] = (i - 1) / len + 1;

	sort(query.begin() + 1, query.end(), [&](auto a, auto b)
	{
		if(bel[a[0]] != bel[b[0]]) return bel[a[0]] < bel[b[0]];
		return a[1] < b[1];
	});

	int siz = b.size();
	vector<int> left(siz, -1), right(siz, -1);
	vector<array<int, 3>> stk;
	auto add = [&](int x, int pos, int &res, bool f) -> void
	{
		if(f) stk.push_back({x, left[x], right[x]});

		if(left[x] == -1) left[x] = right[x] = pos;
		else
		{
			if(pos < left[x]) left[x] = pos;
			if(pos > right[x]) right[x] = pos;
			res = max(res, right[x] - left[x]);
		}
	};
	vector<int> ans(m + 1);
	for(int x = 1; x <= m; )
	{
		int y = x;
		while(y <= m && bel[query[y][0]] == bel[query[x][0]]) y ++;

		int R = min(bel[query[x][0]] * len, n);
		while(x < y && query[x][1] <= R)
		{
			int res = 0;
			auto [l, r, id] = query[x];
			for(int i = l; i <= r; i ++) add(a[i], i, res, false);
			ans[id] = res;
			for(int i = l; i <= r; i ++) left[a[i]] = right[a[i]] = -1;
			x ++;
		}

		int i = R, j = R + 1, res = 0;
		while(x < y)
		{
			auto [l, r, id] = query[x];
			while(i < r) add(a[++ i], i, res, false);
			int backup = res;
			while(j > l) add(a[-- j], j, res, true);
			ans[id] = res;
			while(stk.size())
			{
				auto [x, prel, prer] = stk.back();
				stk.pop_back();
				left[x] = prel, right[x] = prer;
			}
			j = R + 1;
			res = backup;
			x ++;
		}
		for(int i = 0; i < siz; i ++)
			left[i] = right[i] = -1;
	}
	for(int i = 1; i <= m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
