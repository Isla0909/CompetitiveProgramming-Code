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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
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
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1), c(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];
		for(int i = 1; i <= n; i ++) cin >>c[i];
		
		auto check = [&](ll x) -> bool
		{
			vector<ll> d(n + 1); ll sum = 0;
			for(int i = 1; i <= n; i ++)
				d[i] = x / c[i], sum += d[i];
			ll s = accumulate(b.begin() + 1, b.end(), 0LL);
			for(int i = 1; i <= n; i ++)
				if(b[i] > sum - d[a[i]]) return false;
			return s <= sum;
		};
		cerr <<123 <<endl;
		ll l = 0, r = 1e18;
		while(l + 1 != r)
		{
			ll mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid;
		}
		cout <<r <<endl;
	}
	return 0;
}