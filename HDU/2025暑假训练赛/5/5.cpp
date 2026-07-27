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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n = 5000;
		int a, b, c, d; cin >>a >>b >>c >>d;
		vector<int> cnt[5], pre[5], siz(5);
		for(int i = 1; i <= 4; i ++)
		{
			int m; cin >>m;
			siz[i] = m;
			cnt[i].push_back(0); pre[i].assign(m + 1, 0);
			while(m --)
			{
				int x; cin >>x;
				cnt[i].push_back(x);
			}
			sort(cnt[i].begin() + 1, cnt[i].end(), greater<int>());

			for(int j = 1; j <= siz[i]; j ++)
				pre[i][j] = pre[i][j - 1] + cnt[i][j];
			//tell(0, pre[i]);
		}

		i64 ans = 0;
		for(int i = 0; i <= d; i ++)
		{
			for(int j = 0; j <= c; j ++)
			{
				for(int k = 0; k <= b + 2 * (d - i) + (c - j); k ++)
				{
					i64 res = 0;

					res += pre[4][min(i, siz[4])];
					res += pre[3][min(j, siz[3])];
					res += pre[2][min(k, siz[2])];

					int add1 = (c - j) + 2 * (b + 2 * (d - i) + (c - j) - k);

					res += pre[1][min(a + add1, siz[1])];
					ans = max(ans, res);
				}
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}