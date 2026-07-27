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

struct SparseTable
{
	int n, k;
	vector<int> a;
	vector<vector<int>> st;

	SparseTable() {}
	SparseTable(vector<int> &v)
	{
		initial(v);
	}

	void initial(vector<int> &v)
	{
		n = v.size() - 1;
		k = __lg(2 * n - 1) + 1;
		a.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			a[i] = v[i];
		st.assign(n + 1, vector<int>(k));
	}

	void max_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int max_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void min_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int min_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void gcd_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int gcd_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	sort(a.begin() + 1, a.end());

	vector<int> diff(n);
	for(int i = 0; i < n; i ++)
		diff[i] = a[i + 1] - a[i];

	SparseTable st(diff); st.min_work();

	i64 ans = inf;
	for(int i = 1; i + k - 1 <= n; i ++)
	{
		int l = i, r = i + k - 1;
		int pre = st.min_query(l, r - 1), suf = a[r] - a[l];
		ans = min(ans, 1LL * pre * suf);
	}
	cout <<ans <<endl;
	return 0;
}
