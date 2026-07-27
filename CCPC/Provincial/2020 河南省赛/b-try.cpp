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

struct chash {
    const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const {
        x ^= RANDOM;
        x ^= x >> 23;
        x *= 0x2127599bf4325c37ULL;
        x ^= x >> 47;
        return x;
    }
};
unordered_map<int, i64, chash> a;



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> p(n + 1), d(n + 1);
	for(int i = 1; i <= n; i ++) cin >>p[i];
	for(int i = 1; i <= n; i ++) cin >>d[i];

	unordered_map<int, i64, chash> a;
	a[m] = 0;
	for(int i = 1; i <= n; i ++)
	{
		//看广告
		for(auto [c, w] : a)
		{
			// cout <<c <<" " <<w <<endl;
			// cout <<w + 1LL * c * p[i] <<endl;
			// cout <<"c / d[i] " <<c / d[i] <<endl;
			i64 nw = w + 1LL * c * p[i];
			if(a.count(c / d[i])) a[c / d[i]] = max(a[c / d[i]], nw);
			else a[c / d[i]] = nw;
		}
		//a = b;
		//不看
		// for(auto [c, w] : f[i - 1])
		// 	f[i][c] = max(f[i][c], w);

		// cout <<"i: " <<i <<endl;
		// for(auto [c, w] : f[i])
		// 	cout <<c <<" " <<w <<endl; 
		//cout <<endl;
	}
	i64 ans = 0;
	for(auto [c, w] : a)
		ans = max(ans, w);
	cout <<ans <<endl;
	return 0;
}
