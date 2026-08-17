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
	vector<int> c(n + 1);
	for(int i = 1; i <= n; i ++) cin >>c[i];

	vector f(n + 1, vector<int>(n + 1, INF));
	for(int i = 1; i <= n; i ++)
	f[i][i] = 1;

	auto get = [&](int l, int r) -> int
	{
		if(l > r) return 0;
		return f[l][r];
	};

	for(int len = 2; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;

			f[l][r] = 1 + f[l + 1][r];

			if(c[l] == c[l + 1])
				f[l][r] = min(f[l][r], 1 + get(l + 2, r));

			for(int k = l + 2; k <= r; k ++)
				if(c[l] == c[k]) f[l][r] = min(f[l][r], f[l + 1][k - 1] + get(k + 1, r));
		}
	cout <<f[1][n] <<endl;
	return 0;
}
