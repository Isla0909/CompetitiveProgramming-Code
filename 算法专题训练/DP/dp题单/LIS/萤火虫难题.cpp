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

vector<int> minp, primes;
int cnt;

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;
			minp[i * p] = p;
			if(minp[i] == p) break;
		}
	}
	cnt = primes.size();
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(5e5);

	int n; cin >>n;
	vector<int> w(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++) cin >>w[i];
	for(int i = 1; i <= n; i ++) cin >>c[i];

	vector f(2, vector<pii>(5e5 + 1)); int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x = w[i], col = c[i];
		vector<int> div;
		while(x > 1)
		{
			int p = minp[x];
			div.push_back(p);
			while(x % p == 0) x /= p;
		}

		int pre_max = 0;
		for(auto p : div)
		{
			auto [l1, c1] = f[1][p];
			auto [l2, c2] = f[0][p];

			if(col != c1) pre_max = max(pre_max, l1);
			else pre_max = max(pre_max, l2);
		}

		int cur = pre_max + 1;
		ans = max(ans, cur);

		for(auto p : div)
		{
			auto [l1, c1] = f[1][p];
			auto [l2, c2] = f[0][p];

			if(cur > l1)
			{
				f[0][p] = f[1][p];
				f[1][p] = {cur, col};
			}
			else if(col != c1 && cur > f[0][p].se) f[0][p] = {cur, col};
		}

	}
	cout <<ans <<endl;
	return 0;
}