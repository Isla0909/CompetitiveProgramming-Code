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
	int m = (1 + n) * n / 2;
	vector<int> v(m + 1);
	int idx = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= i; j ++)
			v[idx ++] = i;
	vector<int> ans; int best = INF;
	int cnt = 100;
	while(cnt --)
	{
		shuffle(v.begin() + 1, v.end(), rng);
		vector f(m + 1, vector<bool>(m + 1));
		for(int len = 1; len <= m; len ++)
		{
			for(int l = 1; l + len - 1 <= m; l ++)
			{
				int r = l + len - 1;
				if(l == r) f[l][r] = 1;
				else if(r == l + 1) f[l][r] = (v[l] == v[r]);
				else f[l][r] = (f[l + 1][r - 1] && v[l] == v[r]);
			}
		}
		int c = 0;
		for(int i = 1; i <= m; i ++)
			for(int j = i; j <= m; j ++)
				if(f[i][j]) c ++;
		if(c < best)
		{
			best = c;
			ans = v;
		}
	}
	tell(1, ans);
	return 0;
}
