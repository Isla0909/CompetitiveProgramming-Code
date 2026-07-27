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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
		int n; cin >>n;
		vector<pair<int, u64>> a;
		for(int i = 0; i < n; i ++)
		{
			int l, r; cin >>l >>r;
			r ++;
			u64 x = rng();
			a.emplace_back(l, x);
			a.emplace_back(r, x);
		}
		sort(a.begin(), a.end());

		int lst = -1;
		u64 cur = 0;
		vector<i64> s{0};
		for(auto [i, x] : a)
		{
			if(i > lst) s.push_back(cur);

			lst = i;
			cur ^= x;
		}
		sort(s.begin(), s.end());
		cout <<unique(s.begin(), s.end()) - s.begin() <<endl;
	}
	return 0;
}