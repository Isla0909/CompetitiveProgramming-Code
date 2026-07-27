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
			if(p == minp[i]) break;
		}
	}
}

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

	sieve(3e7);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		if(n <= 100)
		{
			bool f = 0;
			for(int i = 1; i <= n && !f; i ++)
				for(int j = i + 1; j <= n; j ++)
					if(__gcd(a[i], a[j]) != 1)
					{
						f = 1;
						cout <<a[i] <<" " <<a[j] <<endl;
						break;
					}
			if(!f) cout <<-1 <<endl;
			continue;
		}

		bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] <= 3e7 && minp[a[i]] == a[i]) continue;
			if(!isprime(a[i]))
			{
				f = 0;
				break;
			}
		}

		if(f)
		{
			cout <<-1 <<endl;
			continue;
		}
		bool h = 0;
		vector<int> ans;
		for(auto p : primes)
		{
			ans.clear();
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] % p == 0)
				{
					ans.push_back(a[i]);
					if(ans.size() >= 2) break;
				}
			}
			if(ans.size() >= 2)
			{
				h = 1;
				break;
			}
		}
		if(h) tell(0, ans);
		else cout <<-1 <<endl;
	}
	return 0;
}
