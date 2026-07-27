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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, ll b, int p = mod)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res % p;
}

int inv(int x)
{
	return quick_pow(x, mod - 2, mod);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int x, y; cin >>x >>y;
		int a, b, _; cin >>a >>b >>_;

		int p = 1LL * a * inv(a + b) % mod, q = 1LL * b * inv(a + b) % mod;

		auto dfs = [&](this auto &&self, int a, int b) -> int
		{
			if(a == b) return p;
			if(a == 1) return quick_pow(p, b);
			if(b == 1) return (1 + mod - quick_pow(q, a));

			if(a > b) return (p + 1LL * q * self(a - b, b) % mod) % mod;
			return 1LL * p * self(a, b - a) % mod;
		};

		int c = dfs(x, y);
		cout <<c <<endl;
	}
	return 0;
}