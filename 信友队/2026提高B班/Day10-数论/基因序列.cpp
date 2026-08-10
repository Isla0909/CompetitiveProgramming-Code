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

	int m = 2e6;
	sieve(m);

	int n, q; cin >>n >>q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> adj(n + 1);
	vector<bool> st(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		st[v] = true;
	}

	int root = 1;
	while(root <= n && st[root]) root ++;

	vector<int> ans(q + 1, -1);
	vector<vector<int>> query(n + 1);
	for(int i = 1; i <= q; i ++)
	{
		int u; cin >>u;
		query[u].push_back(i);
	}

	vector<vector<int>> stk(m + 1);
	vector<int> dep(n + 1); dep[root] = 1;
	auto dfs = [&](auto &&self, int u) -> void
	{
		vector<int> d;
		int x = a[u];
		while(x > 1)
		{
			int p = minp[x];
			d.push_back(p);
			while(x % p == 0) x /= p;
		}

		vector<int> fa;
		for(auto p : d)
		{
			if(stk[p].size()) fa.push_back(stk[p].back());
			stk[p].push_back(u);
		}

		sort(fa.begin(), fa.end(), [&](auto i, auto j)
		{
			return dep[i] > dep[j];
		});

		if(fa.size())
		{
			for(auto id : query[u])
				ans[id] = fa[0];
		}

		for(auto v : adj[u])
		{
			dep[v] = dep[u] + 1;
			self(self, v);
		}

		for(auto p : d)
			stk[p].pop_back();
	};
	dfs(dfs, root);

	for(int i = 1; i <= q; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
