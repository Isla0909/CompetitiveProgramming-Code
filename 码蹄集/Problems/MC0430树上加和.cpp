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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 quick_pow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x)
{
	return quick_pow(x, mod - 2);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		a[i] %= mod;
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
	    int u, v; cin >>u >>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}

	vector<i64> down(n + 1);
	auto dfs1 = [&](auto &&self, int u, int fa) -> void
	{
		i64 res = 1;
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(self, v, u);

			res = res * (1 + down[v]) % mod;
		}
		down[u] = res;
	};
	dfs1(dfs1, 1, -1);

	vector<i64> up(n + 1);
	auto dfs2 = [&](auto &&self, int u, int fa) -> void
	{
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			i64 res = down[u] * inv(1 + down[v]) % mod;
			up[v] = (1 + up[u]) * res % mod;

			self(self, v, u);
		}
	};
	dfs2(dfs2, 1, -1);

	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = (ans + a[i] * down[i] % mod * (1 + up[i]) % mod) % mod;
	cout <<ans <<endl;
	return 0;
}
