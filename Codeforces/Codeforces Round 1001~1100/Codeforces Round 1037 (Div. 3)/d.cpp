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
#define int long long
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
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
		int n, x; cin >>n >>x;
		vector<pii> v(n);
		for(int i = 0; i < n; i ++)
		{
			int a, b, c; cin >>a >>b >>c;
			v[i] = {a, c};
		}
		sort(v.begin(), v.end());

		int ans = x;
		if(x < v[0].ff)
		{
			cout <<x <<endl;
			continue;
		}
		else
		{
			int ed = v[0].se;
			ans = max(ans, ed);

			for(int i = 1; i < n; i ++)
			{
				if(ans < v[i].ff) break;

				ans = max(ans, v[i].se);
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}