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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

i64 mul(i64 a, i64 b, i64 p)
{
	i64 c = a * b - i64(1.0L * a * b / p) * p;

	c %= p;
	if(c < 0) c += p;

	return c;
}

i64 pow(i64 a, i64 b, i64 p)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = mul(res, a, p);

		a = mul(a, a, p);
		b >>= 1;
	}
	return res % p;
}

bool isprime(i64 n)
{
	if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;

	i64 s = __builtin_ctzll(n - 1), d = n >> s;

	for(i64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
	{
		i64 p = pow(a % n, d, n), i = s;
		while(p != 1 && p != n - 1 && a % n && i --) p = mul(p, p, n);
		if(p != n - 1 && i != s) return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		i64 x, y; cin >>x >>y;
		bool f = 0;
		for(i64 i = y - 1; i > x; i --)
			if(__gcd(i, y) == 1 && __gcd(i, x) == 1)
			{
				f = 1;
				cout <<i <<endl;
				break;
			}
		if(!f) cout <<-1 <<endl;
	}

	return 0;
}