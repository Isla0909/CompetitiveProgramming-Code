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

	int T; cin >>T;
	while(T --)
	{
		int n, m, q; cin >>n >>m >>q;
		vector<int> a(n + 1), b(m + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= m; i ++) cin >>b[i];

		sort(a.begin() + 1, a.end(), greater<int>()), sort(b.begin() + 1, b.end(), greater<int>());

		vector<i64> pre1(n + 1), pre2(m + 1);
		for(int i = 1; i <= n; i ++)
			pre1[i] = pre1[i - 1] + a[i];
		for(int i = 1; i <= m; i ++)
			pre2[i] = pre2[i - 1] + b[i];

		auto fun = [&](int tot, int x) -> i64
		{
			return pre1[x] + pre2[tot - x];
		};

		while(q --)
		{
			int x, y, z; cin >>x >>y >>z;
			int l = max(0, z - y), r = min(x, z);
			//cout <<l <<" " <<r <<endl;
			while(r - l > 2)
			{
				int mid1 = l + (r - l) / 3;
				int mid2 = r - (r - l) / 3;

				if(fun(z, mid1) >= fun(z, mid2)) r = mid2;
				else l = mid1;
			}
			i64 res = 0;
			for(int i = l; i <= r; i ++)
				res = max(res, fun(z, i));
			cout <<res <<endl;
		}
	}
	return 0;
}