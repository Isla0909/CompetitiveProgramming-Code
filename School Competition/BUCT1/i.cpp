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

	int n; cin >>n;
	vector<int> a(n + 1), b(n);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i < n; i ++) cin >>b[i];
	
	vector<array<int, 4>> f(n + 1, {-INF, -INF, -INF, -INF});
	f[1][0] = 0;
	for(int i = 2; i <= n; i ++)
	{
		//不选
		for(int j = 0; j <= 3; j ++)
			if(f[i - 1][j] >= b[i - 1]) f[i][j] = max(f[i][j], f[i - 1][j] - b[i - 1]);

		//选
		for(int j = 1; j <= 3; j ++)
			if(f[i - 1][j - 1] + a[i - 1] >= b[i - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i - 1] - b[i - 1]);
	}

	int ans = -1;
	for(int i = 0; i <= 2; i ++)
		ans = max(ans, f[n][i] + a[n]);
	ans = max(ans, f[n][3]);
	cout <<ans <<endl;
	return 0;
}
