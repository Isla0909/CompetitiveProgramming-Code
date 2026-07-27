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
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto check = [&](int x) -> bool
	{
		for(int i = 2; i <= n; i ++)
			if(a[i] + a[i - 1] > x) return false;

		vector<int> minn(n + 1), maxx(n + 1);
		minn[1] = mmax[1] = a[1];
		for(int i = 2; i <= n; i ++)
		{
			minn[i] = min(a[i], a[1] - mmin[i - 1]);
			maxx[i] = max(0, a[1] - x + a[i - 1] - mmax[i - 1] + a[i]);
		}
		return minn[n] == 0;
	};

	if(n == 1)
	{
		cout <<a[1] <<endl;
		return 0;
	}

	int l = 0, r = 3e5 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout <<r <<endl;
	return 0;
}
