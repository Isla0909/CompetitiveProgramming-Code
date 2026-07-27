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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
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
	cin.tie(0) -> sync_with_stdio(false);

	sieve(1e6);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> p(n + 1, -1); p[1] = 1;
		vector<bool> st(n + 1);

		for(auto it = primes.rbegin(); it != primes.rend(); it ++)
		{
			vector<int> cycle;
			for(int i = *it; i <= n; i += *it)
			{
				if(p[i] == -1) cycle.push_back(i);
			}
			for(int i = 0; i < cycle.size(); i ++)
				p[cycle[i]] = cycle[(i + 1) % cycle.size()];
		}
		for(int i = 1; i <= n; i ++)
			if(p[i] == -1) p[i] = i;
		for(int i = 1; i <= n; i ++)
			cout <<p[i] <<" \n"[i == n];
	}
	return 0;
}