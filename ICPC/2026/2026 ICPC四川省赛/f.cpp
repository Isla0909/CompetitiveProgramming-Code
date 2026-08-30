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
		vector<i64> a(n + 1); i64 gcd = 0;
		for(int i = 1; i <= n; i ++) 
		{
			cin >>a[i];
			gcd = __gcd(gcd, a[i]);
		}

		for(int i = 1; i <= n; i ++)
			a[i] /= gcd;

		auto get = [&](i64 x) -> vector<i64>
		{
			vector<i64> d;
			for(i64 p = 2; p * p <= x; p ++)
			{
				if(x % p) continue;
				d.push_back(p);
				while(x % p == 0) x /= p;
			}
			if(x > 1) d.push_back(x);
			return d;
		};
		auto d1 = get(a[1]), d2 = get(a[2]);
		vector<i64> v;
		for(auto p : d1)
			v.push_back(p);
		for(auto p : d2)
			v.push_back(p);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		auto check = [&](i64 p) -> bool
		{
			vector<i64> b{0};
			for(int i = 1; i <= n; i ++)
				if(a[i] % p)
					b.push_back(a[i]);

			int m = b.size() - 1;
			if(m <= 1) return true;
			
			vector<i64> pre(m + 1), suf(m + 2);
			for(int i = 1; i <= m; i ++)
				pre[i] = __gcd(pre[i - 1], b[i]);
			for(int i = m; i >= 1; i --)
				suf[i] = __gcd(suf[i + 1], b[i]);

			for(int i = 1; i <= m; i ++)
			{
				i64 d = __gcd(pre[i - 1], suf[i + 1]);
				if(d > 1) return true; 
			}
			return false;
		};

		bool f = false;
		for(auto p : v)
		{
			if(check(p))
			{
				f = true;
				break;
			}
		}
		cout <<(f ? "YES" : "NO") <<endl;
	}
	return 0;
}
