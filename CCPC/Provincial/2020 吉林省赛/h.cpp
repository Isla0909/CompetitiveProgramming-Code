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
			primes.push_back(i);
			Mu[i] = -1;
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(minp[i] == p) break;
			Mu[i * p] = -Mu[i];
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(1e5);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector<int> cnt(m + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			cnt[x] ++;
		} 

		vector<int> div(m + 1);
		for(int d = 1; d <= m; d ++)
			for(int j = d; j <= m; j += d)
				div[d] += cnt[j];

		vector<i64> ans(m + 1);
		for(int x = 1; x <= m; x ++)
			for(int d = 1; d <= m / x; d ++)
				ans[x] += 1LL * Mu[d] * div[x * d] * div[x * d];

		while(k --)
		{
			int x; cin >>x;
			cout <<ans[x] <<endl;
		}
	}
	return 0;
}
