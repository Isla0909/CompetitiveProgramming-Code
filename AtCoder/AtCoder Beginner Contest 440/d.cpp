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

	int n, q; cin >>n >>q;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) cin >>a[i];
	
	sort(a.begin(), a.end());

	auto get = [&](i64 l, i64 r) -> int
	{
		int t1 = lower_bound(a.begin(), a.end(), l) - a.begin();
		int t2 = upper_bound(a.begin(), a.end(), r) - a.begin();
		return t2 - t1;
	};

	auto check = [&](i64 l, i64 r, int y) -> bool
	{
		int c = get(l, r);
		return r - l + 1 - c <= y;
	};

	while(q --)
	{
		int x, y; cin >>x >>y;
		i64 l = x, r = 3e9;
		while(l + 1 != r)
		{
			i64 mid = l + r >> 1;
			if(check(x, mid, y)) l = mid;
			else r = mid;
		}
		i64 lo = 0, hi = l + 1;
		while(lo + 1 != hi)
		{
			i64 mid = lo + hi >> 1;
			if(get(mid, l) == l - mid + 1) hi = mid;
			else lo = mid;
		}	
		cout <<lo <<endl;
	}
	return 0;
}
