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

	int n; cin >>n;

	sieve(n);

	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j * i <= n; j ++)
			if(minp[j] == j)
			{
				adj[i].push_back(j * i);
				deg[j * i] ++;
			}
	queue<int> q;
	vector<i64> f(n + 1);
	f[1] = 1;
	for(int i = 1; i <= n; i ++)
		if(!deg[i]) q.emplace(i);

	while(q.size())
	{
		auto u = q.front(); q.pop();
		for(auto v : adj[u])
		{
			f[v] = (f[v] + f[u]) % mod;
			deg[v] --;
			if(!deg[v]) q.emplace(v);
		}
	}
	int m; cin >>m;
	while(m --)
	{
		int x; cin >>x;
		cout <<f[x] <<endl;
	}
	return 0;
}
