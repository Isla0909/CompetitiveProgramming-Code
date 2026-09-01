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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<i64> a(n + 2);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		/*
            mx[r]：
            所有右端点恰好为 r 的需求区间中，
            最大的左端点。
        */
		int m; cin >>m;
		vector<int> mx(n + 2);
		for(int i = 0; i < m; i ++)
		{
			int l, r; cin >>l >>r;
			mx[r] = max(mx[r], l);
		}

		for(int i = 1; i <= n + 1; i ++)
			mx[i] = max(mx[i], mx[i - 1]);

		a[n + 1] = 0;
		vector<i64> f(n + 2, inf);
		f[0] = 0;
		deque<int> q;
		q.emplace_back(0);

		for(int i = 1; i <= n + 1; i ++)
		{
			//L <= j < i
			int L = mx[i - 1];
			while(q.size() && q.front() < L) 
				q.pop_front();

			f[i] = f[q.front()] + a[i];

			while(q.size() && f[i] <= f[q.back()]) 
				q.pop_back();

			q.emplace_back(i);
		}
		cout <<f[n + 1] <<endl;
	}
	return 0;
}
