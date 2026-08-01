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

	int n, m, x, y, z; cin >>n >>m >>x >>y >>z;
	vector<int> a(x + 1), b(y + 1), c(z + 1);
	for(int i = 1; i <= x; i ++) cin >>a[i];
	for(int i = 1; i <= y; i ++) cin >>b[i];
	for(int i = 1; i <= z; i ++) cin >>c[i];

	sort(a.begin() + 1, a.end(), greater<int>());
	sort(b.begin() + 1, b.end(), greater<int>());

	vector<int> v;
	for(int i = 1; i <= n; i ++)
		v.push_back(a[i]);
	for(int i = 1; i <= m; i ++)
		v.push_back(b[i]);
	for(int i = 1; i <= z; i ++)
		v.push_back(c[i]);
	sort(v.begin(), v.end(), greater<int>());
	cout <<accumulate(v.begin(), v.begin() + n + m, 0LL) <<endl;
	return 0;
}
