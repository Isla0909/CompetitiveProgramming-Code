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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f;

int quick_pow(int a, ll b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a;

		a = 1LL * a * a;
		b >>= 1;
	}
	return res;
}


ll C(int a, int b)
{
	if(a < 0 || b < 0 || a < b) return 0;

	ll res = 1;
	for(int i = 1, j = a; i <= b; i ++, j --)
	{
		res = res * j;
		res = res / i;
	}
	return res;
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n), cnt(1e6 + 1);
		for(auto &x : a)
		{
			cin >>x;
			cnt[x] ++;
		}
		sort(a.begin(), a.end());

		auto get = [&](int x) -> int
		{
			return lower_bound(a.begin(), a.end(), x) - a.begin();
		};

		ll ans = 0, sum = 0;
		vector<int> st(1e6 + 1);
		for(int i = 0; i < n; i ++)
		{
			if(cnt[a[i]] < k) continue;

			if(st[a[i]])
		}
		cout <<ans <<endl;
	}
	return 0;
}