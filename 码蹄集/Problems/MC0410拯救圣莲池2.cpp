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

	int n, k; cin >>n >>k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto check = [&](int x) -> i64
	{
		i64 s = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] < x) continue;
			s += a[i] - x;
		}
		return s;
	};

	int l = -1, r = *max_element(a.begin() + 1, a.end()) + 1;;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid) >= k) l = mid;
		else r = mid;
	}
	
	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] <= r) continue;
		k -= (a[i] - r);
		int L = r + 1, R = a[i];
		ans += 1LL * (L + R) * (R - L + 1) / 2;
		a[i] = r;
	}
	
	priority_queue<int> q;
	for(int i = 1; i <= n; i ++)
		q.push(a[i]);

	while(k --)
	{
		auto t = q.top(); q.pop();
		ans += t;
		q.push(t - 1);
	}
	cout <<ans <<endl;
	return 0;
}
