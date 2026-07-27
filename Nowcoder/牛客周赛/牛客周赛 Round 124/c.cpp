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

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >>a[i];

		if(m > n + 1)
		{
			cout <<"NO" <<endl;
			continue;
		}

		sort(a.begin(), a.end());

		auto get = [&](int l, int r) -> int
		{
			int t1 = lower_bound(a.begin(), a.end(), l) - a.begin();
			int t2 = upper_bound(a.begin(), a.end(), r) - a.begin();
			return t2 - t1;
		};

		bool f = 0;
		for(int i = 0; i < n; i ++)
		{
			int l = a[i], r = a[i] + m - 1;
			int c = get(l, r);
			if(c == m - 1)
			{
				f = 1;
				break;
			}
		}
		cout <<(f ? "YES" : "NO") <<endl;
	}
	return 0;
}
