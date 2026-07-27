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

bool isprime(i64 n)
{
	if(n <= 50000000) return minp[n] == n;

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

bool check(int x)
{
	while(x)
	{
		int t = x % 10;
		if(t != 3 && t != 6 && t != 7) return false;
		x /= 10;
	}
	return true;
}

bool judge(int x, char c)
{
	string s = to_string(x);
	for(int i = 0; i + 1 < s.size(); i ++)
		if(s[i] == '7' && s[i + 1] == c) return true;
	return false;
}

int dx[] = {3, 6, 7};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(5e7);

	int n; cin >>n;
	vector<int> v;
	auto dfs = [&](auto &&self, int u, i64 x, bool f1, bool f2)
	{
		if(u == n)
		{
			if(f1 && f2 && isprime(x))
			{
				v.push_back(x);
			}
			return ;
		}
		for(int i = 0; i < 3; i ++)
		{
			i64 nx = x * 10 + dx[i];

			bool nf1 = f1, nf2 = f2;
			if(u)
			{
				if(x % 10 == 7)
				{
					if(dx[i] == 3) nf1 = 1;
					if(dx[i] == 6) nf2 = 1;
				}
			}

			self(self, u + 1, nx, nf1, nf2);
		}
	};
	dfs(dfs, 0, 0, 0, 0);
	cout <<v.size() <<endl;
	for(auto x : v)
		cout <<x <<endl;
	return 0;
}
