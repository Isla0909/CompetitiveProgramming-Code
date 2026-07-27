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
	vector<int> a(2 * n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		a[i] = a[i + n] = x; 
	}
	vector<i64> pre(2 * n + 1);
	for(int i = 1; i <= 2 * n; i ++)
		pre[i] = pre[i - 1] + a[i];

	auto check = [&](i64 x) -> bool
	{
		for(int i = 1; i <= n; i ++)
		{
			auto it1 = lower_bound(pre.begin() + i, pre.begin() + i + n, x + pre[i - 1]);
			if(it1 == pre.begin() + i + n) return false;
			int idx1 = it1 - pre.begin();
			auto it2 = lower_bound(pre.begin() + idx1 + 1, pre.begin() + i + n, x + pre[idx1]);
			if(it2 == pre.begin() + i + n) return false;
			int idx2 = it2 - pre.begin();
			if(pre[i + n - 1] - pre[idx2] >= x) return true; 
		}
		return false;
	};

	i64 l = 0, r = 1e14;
	while(l + 1 != r)
	{
		i64 mid = l + r >> 1LL;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout <<l <<endl;
	return 0;
}
