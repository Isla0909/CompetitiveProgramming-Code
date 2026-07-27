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

	int w, h, n; cin >>w >>h >>n;

	int m = h - n + 1;
	vector<vector<int>> mmin(w + 1, vector<int>(m + 1)), mmax(w + 1, vector<int>(m + 1));
	for(int i = 1; i <= w; i ++)
	{
		vector<int> a(h + 1);
		for(int j = 1; j <= h; j ++)
			cin >>a[j];
		multiset<int> s;
		for(int j = 1; j <= n; j ++)
			s.insert(a[j]);

		mmin[i][1] = *s.begin(), mmax[i][1] = *s.rbegin();
		for(int j = 2; j <= m; j ++)
		{
			s.extract(a[j - 1]);
			s.insert(a[j + n - 1]);

			mmin[i][j] = *s.begin(), mmax[i][j] = *s.rbegin();
		}
	}

	int ans = INF;
	for(int j = 1; j <= m; j ++)
	{
		multiset<int> smin, smax;
		for(int i = 1; i <= n; i ++)
		{
			smin.insert(mmin[i][j]);
			smax.insert(mmax[i][j]);
		}
		ans = min(ans, *smin.begin() + *smax.rbegin());

		for(int i = 2; i + n - 1 <= w; i ++)
		{
			smin.extract(mmin[i - 1][j]);
			smax.extract(mmax[i - 1][j]);

			smin.insert(mmin[i + n - 1][j]);
			smax.insert(mmax[i + n - 1][j]);

			ans = min(ans, *smin.begin() + *smax.rbegin());
		}
	}
	cout <<ans <<endl;
	return 0;
}
