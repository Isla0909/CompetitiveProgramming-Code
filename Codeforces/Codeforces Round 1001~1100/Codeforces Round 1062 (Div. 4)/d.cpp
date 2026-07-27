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

constexpr int N = 1e7, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(1e7);
	vector<int> p;
	for(auto x : primes)
		if(x & 1) p.push_back(x);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int cnt = 0;
		vector<i64> a(n);
		for(int i = 0; i < n; i ++)
		{
			i64 x; cin >>x; a[i] = x;
			if(x & 1) cnt ++;
		}
		if(cnt) cout <<2 <<endl;
		else//全是偶数
		{	
			for(auto x : p)
			{
				bool f = 0;
				for(int i = 0; i < n; i ++)
					if(a[i] % x)
					{
						f = 1;
						break;
					}
				if(f)
				{
					cout <<x <<endl;
					break;
				}
			}
		}
	}
	return 0;
}