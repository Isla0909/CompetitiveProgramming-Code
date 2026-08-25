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

	int n, q; cin >>n >>q;
	vector<int> w(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++) cin >>w[i];
	for(int i = 1; i <= n; i ++) cin >>c[i];

	vector<i64> f(n + 1, -inf);
	while(q --)
	{
		i64 a, b; cin >>a >>b;
		i64 mx1 = 0, mx2 = 0;
		int c1 = -1, c2 = -1;
		
		auto add = [&](int col, i64 val)
		{
			if(col == c1) mx1 = max(mx1, val);
			else if(col == c2)
			{
				mx2 = max(mx2, val);
				if(mx2 > mx1)
				{
					swap(mx1, mx2);
					swap(c1, c2);
				}
			}
			else
			{
				if(val > mx1)
				{
					mx2 = mx1;
					c2 = c1;

					mx1 = val;
					c1 = col;
				}
				else if(val > mx2)
				{
					mx2 = val;
					c2 = col;
				}
			}
		};

		for(int i = 1; i <= n; i ++)
		{
			int col = c[i];

			i64 now = f[col];
			if(now != -inf) now += a * w[i];

			i64 other = (col != c1 ? mx1 : mx2);
			if(other != -inf) now = max(now, other + b * w[i]);

			f[col] = max(f[col], now);
			add(col, f[col]);
		}

		if(q) fill(f.begin(), f.end(), -inf);
		cout <<mx1 <<endl;
	}
	return 0;
}
