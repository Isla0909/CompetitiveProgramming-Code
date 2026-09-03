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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

i64 qpow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; i64 m; cin >>n >>m;
		vector<array<i64, 2>> v(n);
		for(auto &[b, a] : v)
			cin >>a >>b;

		sort(v.begin(), v.end(), greater<>());

		i64 ans = 0;
		i128 res = 0;
		i64 pre = v[0][0];

		for(auto [b, a] : v)
		{
			i64 d = pre - b;
			
			if(res >= (i128)2e14) break;
			if(res > 0 && d >= 50) break;

			if(res) res <<= d;

			if(res >= a) res -= a;
			else
			{
				i64 need = a - (i64)res;
				i64 cnt = (need + m - 1) / m;
				ans = (ans + cnt % mod * qpow(2, b) % mod) % mod;
				res = res + (i128)cnt * m - a;
			}

			pre = b;
		}
		cout <<ans <<endl;
	}
	return 0;
}
