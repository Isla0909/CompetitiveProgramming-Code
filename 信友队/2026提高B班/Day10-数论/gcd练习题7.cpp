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

vector<int> minp, primes;
vector<int> Mu, preMu;
void sieve(int n)
{
	minp.assign(n + 1, 0);
	Mu.assign(n + 1, 0);
	preMu.assign(n + 1, 0);
	primes.clear();

	Mu[1] = 1;

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			Mu[i] = -1;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
			Mu[i * p] = -Mu[i];
		}
	}
	for(int i = 1; i <= n; i ++)
		preMu[i] = preMu[i - 1] + Mu[i];
}

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

	int n, k, l, r; cin >>n >>k >>l >>r;
	int a = (l + k - 1) / k, b = r / k;

	int m = b - a + 1;

	sieve(m);

	i64 ans = (a == 1);
	for(int d = 1; d <= m; d ++)
	{
		if(Mu[d] == 0) continue;

		i64 c = b / d - (a - 1) / d;
		i64 v = (qpow(c, n) - c + mod) % mod;
		ans = (ans + Mu[d] * v) % mod;

		if(ans < 0) ans += mod;
	}
	cout <<ans <<endl;
	return 0;
}
