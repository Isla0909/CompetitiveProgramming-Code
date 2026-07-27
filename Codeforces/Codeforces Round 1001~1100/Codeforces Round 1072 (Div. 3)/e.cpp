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

//diiff[i]:以i为最小值的数量

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> p(n + 1);
		for(int i = 1; i <= n; i ++) cin >>p[i];

		vector<int> d(n);
		for(int i = 1; i < n; i ++)
			d[i] = abs(p[i] - p[i + 1]);

		vector<int> l(n), stk;//左边第一个比我小的数
		for(int i = 1; i <= n - 1; i ++)
		{
			while(stk.size() && d[stk.back()] >= d[i]) stk.pop_back();
			if(stk.size()) l[i] = stk.back();
			else l[i] = 0;

			stk.push_back(i);
		}

		stk.clear();

		vector<int> r(n);
		for(int i = n - 1; i >= 1; i --)
		{
			while(stk.size() && d[stk.back()] > d[i]) stk.pop_back();
			if(stk.size()) r[i] = stk.back();
			else r[i] = n;

			stk.push_back(i);
 		}

 		tell(1, d);
 		tell(1, l), tell(1, r);
 		

 		vector<i64> diff(n);
 		for(int i = 1; i < n; i ++)
 		{
 			int L = 1, R = d[i];
 			i64 c = 1LL * (i - l[i]) * (r[i] - i);;

 			diff[L] += c;
 			if(R + 1 < n) diff[R + 1] -= c;
 		}
 		for(int i = 1; i < n; i ++)
 			diff[i] += diff[i - 1];
 		for(int i = 1; i < n; i ++)
 			cout <<diff[i] <<" \n"[i == n - 1];

 		//cout <<endl;
	}


	return 0;
}
