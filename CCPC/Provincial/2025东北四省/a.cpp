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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector st1(n + 1, vector<int>(18)), st2(n + 1, vector<int>(18));
	for(int j = 0; j <= 17; j ++)
		for(int i = 1; i + (1 << j) - 1 <= n; i ++)
		{
			if(!j) st1[i][0] = st2[i][0] = a[i];
			else
			{
				st1[i][j] = min(st1[i][j - 1], st1[i + (1 << j - 1)][j - 1]);
				st2[i][j] = __gcd(st2[i][j - 1], st2[i + (1 << j - 1)][j - 1]);
			}
		}

	auto query = [&](int op, int l, int r) -> int
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		if(op & 1) return min(st1[l][k], st1[r - (1 << k) + 1][k]);
		return __gcd(st2[l][k], st2[r - (1 << k) + 1][k]);
	};

	auto bl = [&](int left, int right, int pos) ->int
	{
		int l = left - 1, r = right + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(query(1, mid, pos) == a[pos] and query(2, mid, pos) == a[pos])
				r = mid;
			else l = mid;
		}
		return r;
	};
	auto br = [&](int left, int right, int pos) ->int
	{
		int l = left - 1, r = right + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(query(1, pos, mid) == a[pos] and query(2, pos, mid) == a[pos])
				l = mid;
			else r = mid;
		}
		return l;
	};

	int mmax = *max_element(a.begin() + 1, a.end());
	vector<int> left(mmax + 1);

	ll ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int l = bl(left[a[i]] + 1, i, i), r = br(i, n, i);
		left[a[i]] = i;
		ans += 1LL * (i - l + 1) * (r - i + 1);
	}
	cout <<ans <<endl;
	return 0;
}