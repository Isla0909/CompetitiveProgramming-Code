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

	int n, m, l; cin >>n >>m >>l;
	vector<int> a(n + 1), b(m + 1);
	vector<i64> pre(n + 1), v;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = pre[i - 1] + a[i];
		v.emplace_back(pre[i]);
	}
	for(int i = 1; i <= m; i ++) cin >>b[i];

	auto check = [&](i64 L, i64 R) -> bool
	{
		auto it = upper_bound(v.begin(), v.end(), L);
		if(it == v.end()) return false;
		return *it < R;
	};

	i64 L = 0, R = l; bool f = check(L, R);
	for(int i = 1; i <= m && !f; i ++)
	{
		L += b[i], R += b[i];
		f = check(L, R);
	}
	cout <<(f ? "YES" : "NO") <<endl;
	return 0;
}
