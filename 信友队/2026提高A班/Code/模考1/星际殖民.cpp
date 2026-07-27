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

	freopen("colony.in", "r", stdin);
	freopen("colony.out", "w", stdout);

	int T; cin >>T;
	while(T --)
	{
		int n, k, m; cin >>n >>k >>m;

		auto check = [&](int x) -> bool
		{
			int l = k - 1, r = n - k;
			int lo = max(0, x - r), hi = min(l, x);

			if(lo > hi) return false;

			int mid = x / 2, a, b;
			if(hi < mid) a = hi;
			else if(lo > mid) a = lo;
			else a = mid;
			b = x - a;

			return a + b + max(a, b) - 1 <= m;
		};


		int l = 0, r = n + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}	
		cout <<l + 1 <<endl;
	}
	return 0;
}
