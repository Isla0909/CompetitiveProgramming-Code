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

	i64 inv2 = qpow(2, mod - 2);
	//cout <<inv2 <<endl;

	i64 n, m; cin >>n >>m;
	i64 ans = n % mod * (m % mod) % mod;
	for(i64 l = 1, r; l <= min(n, m); l = r + 1)
	{
		i64 q = n / l;
		r = n / q;
		r = min(r, min(n, m));
		//cout <<l <<" " <<r <<" " <<q <<endl;
		ans -= q % mod * ((l + r) % mod) % mod * ((r - l + 1) % mod) % mod * inv2 % mod;
		//cout <<q % mod * (l + r) % mod * (r - l + 1) % mod * inv2 % mod <<endl;
		if(ans < 0) ans += mod;
	}
	cout <<ans <<endl;
	return 0;
}
