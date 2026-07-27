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

i64 lcm(int a, int b)
{
	return 1LL * a * b / __gcd(a, b); 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y; cin >>n >>x >>y;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	sort(a.begin() + 1, a.end());
	
	i64 s = lcm(x, y);
	int c1 = s / x, c2 = s / y;
	int delta = c1 - c2;
	bool f = 1;
	for(int i = 1; i < n; i ++)
		if((a[i + 1] - a[i]) % delta)
		{
			f = 0;
			break;
		}

	int diff = a[n] - a[1];
	if(1LL * diff * c1 / delta > a[n]) f = 0;

	vector<int> cnt(n + 1);
	for(int i = n - 1; i >= 1; i --)
	{
		int c = a[i + 1] - a[i];
		cnt[i] = cnt[i + 1] + c / delta * c2;
	}
	
	int c = a[n] - diff * c1 / delta;
	for(int i = 1; i <= n; i ++)
	{
		cnt[i] += c;
		if(cnt[i] > a[i])
		{
			f = 0;
			break;
		}
	}

	i64 tar = 1LL * (a[1] - cnt[1]) * x + 1LL * cnt[1] * y;
	for(int i = 2; i <= n && f; i ++)
	{
		if(1LL * (a[i] - cnt[i]) * x + 1LL * cnt[i] * y != tar)
		{
			f = 0;
			break;
		}
	}
	cout <<(f ? accumulate(cnt.begin() + 1, cnt.end(), 0LL) : -1) <<endl;
	return 0;
}
