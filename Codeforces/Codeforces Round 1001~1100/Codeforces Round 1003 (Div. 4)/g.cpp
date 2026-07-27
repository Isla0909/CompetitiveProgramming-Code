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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
vector<int> primes, min_from;

void sieve(int n)
{
	min_from.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!min_from[i])
		{
			min_from[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			min_from[i * p] = p;
			if(min_from[i] == p) break;
		}
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		sort(a.begin(), a.end());
		vector<int> cnt(n + 1);

		int cnt_primes = 0;
		sieve(n);

		ll ans = 0;
		for(auto x : a)
		{
			int p = min_from[x];

			if(x == p)//x本身是质数, 找到其他不同的质数
			{
				ans += cnt_primes - cnt[p];
				cnt_primes ++, cnt[p] ++;
			}
			else
			{
				int q = x / p;
				if(q != min_from[q]) continue;

				ans ++;
				if(p == q)
				{
					ans += cnt[x];
					ans += cnt[p];
				}
				else
				{
					ans += cnt[x];
					ans += cnt[p];
					ans += cnt[q];
				}
				cnt[x] ++;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}