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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> col(n + 1);
	for(int i = 1; i <= n; i ++) cin >>col[i];

	vector<vector<int>> adj(n + 1);	
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> siz(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		if(fa != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa));
		siz[u] = 1;
		for(auto &v : adj[u])
		{
			self(v, u);

			siz[u] += siz[v];
			if(siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
		}
	};

	dfs(1, -1);

	vector<int> cnt(n + 1);
	vector<i64> sum(n + 1), ans(n + 1);
	int M = 0;
	sum[0] = 1LL * (1 + n) * n / 2;

	auto addv = [&](int x, int c) -> void
	{
		sum[cnt[x]] -= x;
		cnt[x] += c;
		M = max(M, cnt[x]);
		sum[cnt[x]] += x;

		while(M >= 0 && !sum[M]) M --;
	};

	auto add = [&](this auto &&self, int u, int c) -> void
	{
		addv(col[u], c);
		for(auto v : adj[u])
			self(v, c);
	};

	auto calc = [&](this auto &&self, int u) -> void
	{
		for(auto v : adj[u])
		{
			if(v == adj[u][0]) continue;
			self(v);
			add(v, -1);
		}

		if(adj[u].size())
		{
			self(adj[u][0]);
			for(auto v : adj[u])
			{
				if(v == adj[u][0]) continue;
				add(v, 1);
			}
		}
		addv(col[u], 1);
		ans[u] = sum[M];
	};
	calc(1);
	for(int i = 1; i <= n; i ++)
		cout <<ans[i] <<" \n"[i == n];
	return 0;
}
