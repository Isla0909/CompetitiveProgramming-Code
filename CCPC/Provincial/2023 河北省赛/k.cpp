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
vector<ll> pre;
int cnt;

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear(); cnt = 0;

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
	
	cnt = primes.size();
	pre.assign(cnt + 1, 0);
	for(int i = 1; i <= cnt; i ++)
	    pre[i] = pre[i - 1] + primes[i - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(100000);

	int n; cin >>n;
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);

	auto check = [&](vector<int> &v) -> bool
	{
		for(int i = 0; i < v.size(); i ++)
		{
			int x = abs(v[i] - v[(i + 1) % v.size()]);
			if(x == 1 || minp[x] != x) return false;
		}
		return true;
	};

	

	if(n < 5) cout <<-1 <<endl;
	else
	{
		if(n < 14)
		{
			while(!check(p))
			{
				shuffle(p.begin(), p.end(), rng);
			}
			assert(check(p));
			tell(0, p);
		}
		else if(n & 1)
		{
			vector<int> ans;
			for(int i = 1; i <= n; i += 2)
			{
				ans.push_back(i);
				if(i == 5) ans.push_back(2);
			}
			for(int i = n - 3; i >= 4; i -= 2)
				ans.push_back(i);

			int x = n - 1;
			for(int i = 0; i + 1 < ans.size(); i ++)
			{
				int a = abs(x - ans[i]), b = abs(ans[i + 1] - x);
				if(minp[a] == a && minp[b] == b)
				{
					ans.insert(ans.begin() + i + 1, x);
					break;
				}
			}
			assert(check(ans));
			tell(0, ans);
			//差一个n - 1
		}
		else
		{
			vector<int> ans;
			for(int i = 1; i <= n - 3; i += 2)
			{
				ans.push_back(i);
				if(i == 5) ans.push_back(2);
			}
			for(int i = n; i >= 4; i -= 2)
				ans.push_back(i);

			int x = n - 1;
			for(int i = 0; i + 1 < ans.size(); i ++)
			{
				int a = abs(x - ans[i]), b = abs(ans[i + 1] - x);
				if(minp[a] == a && minp[b] == b)
				{
					ans.insert(ans.begin() + i + 1, x);
					//cout <<i <<endl;
					break;
				}
				 
			}
			assert(check(ans));
			tell(0, ans);
		}
	}


	return 0;
}
