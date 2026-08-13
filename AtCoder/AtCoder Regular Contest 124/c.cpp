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

vector<int> div(int x)
{
	vector<int> d;
	for(int i = 1; i * i <= x; i ++)
	{
		if(x % i) continue;
		d.push_back(i);
		if(i * i != x) d.push_back(x / i);
	}
	return d;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >>a[i] >>b[i];

	auto da = div(a[0]), db = div(b[0]);
	vector<pair<i64, i64>> ma(da.size()), mb(db.size());
	for(int i = 0; i < da.size(); i ++)
	{
		int d = da[i];
		i64 x = 0, y = 0;
		for(int j = 0; j < n; j ++)
		{
			if(a[j] % d == 0) x |= 1LL << j;
			if(b[j] % d == 0) y |= 1LL << j; 
		} 
		ma[i] = {x, y};
	}
	for(int i = 0; i < db.size(); i ++)
	{
		int d = db[i];
		i64 x = 0, y = 0;
		for(int j = 0; j < n; j ++)
		{
			if(a[j] % d == 0) x |= 1LL << j;
			if(b[j] % d == 0) y |= 1LL << j; 
		} 
		mb[i] = {x, y};
	}

	i64 ans = 0;
	for(int i = 0; i < da.size(); i ++)
	{
		auto [ax, ay] = ma[i];
		for(int j = 0; j < db.size(); j ++)
		{
			auto [bx, by] = mb[j];
			i64 ok = (ax & by) | (ay & bx);
			if(ok == (1LL << n) - 1)
			{
				i64 d = __gcd(da[i], db[j]);
				i64 lcm = da[i] / d * db[j];

				ans = max(ans, lcm);
			}
		}
	}
	cout <<ans <<endl;
	return 0;
}
