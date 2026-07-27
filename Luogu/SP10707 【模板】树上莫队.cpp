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

	int n, m; cin >>n >>m;
	vector<int> a(n + 1), b;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 1; i <= n; i ++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dep(n + 1); int len = __lg(2 * n - 1);
	vector f(n + 1, vector<int>(len));
	vector<int> seq(2 * n + 1), first(n + 1), last(n + 1); int cur = 1; 
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		f[u][0] = fa;
		dep[u] = dep[fa] + 1;

		first[u] = cur ++;
		seq[first[u]]  = u;

		for(int k = 1; k < len; k ++)
			f[u][k] = f[f[u][k - 1]][k - 1];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
		}
		last[u] = cur ++;
		seq[last[u]] = u;
	};

	auto lca = [&](int a, int b) -> int
	{
		if(dep[a] < dep[b]) swap(a, b);

		for(int k = len - 1; k >= 0; k --)
			if(dep[f[a][k]] >= dep[b])
				a = f[a][k];
		if(a == b) return b;

		for(int k = len - 1; k >= 0; k --)
			if(f[a][k] != f[b][k])
			{
				a = f[a][k];
				b = f[b][k];
			}
		return f[a][0];
	};

	dfs(1, 0);

	int B = 2 * n / min(2 * n, (int)sqrt(m));
	vector<int> bel(2 * n + 1);
	for(int i = 1; i <= 2 * n; i ++)
		bel[i] = (i - 1) / B + 1; 

	vector<array<int, 4>> query(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int u, v; cin >>u >>v;
		if(first[u] > first[v]) swap(u, v);

		int p = lca(u, v);
		if(u == p) query[i] = {i, first[u], first[v], -1};
		else query[i] = {i, last[u], first[v], p};
	}

	sort(query.begin() + 1, query.end(), [&](const auto &a, const auto &b)
	{
		if(bel[a[1]] != bel[b[1]]) return bel[a[1]] < bel[b[1]];
		if(bel[a[1]] & 1) return a[2] < b[2];
		return a[2] > b[2];
	});

	int siz = b.size();
	vector<int> st(n + 1), cnt(siz);
	int l = 1, r = 0, res = 0;
	
	auto add = [&](int u) -> void
	{
		st[u] ^= 1;
		if(st[u])
		{
			cnt[a[u]] ++;
			if(cnt[a[u]] == 1) res ++;
		}
		else
		{
			cnt[a[u]] --;
			if(!cnt[a[u]]) res --;
		}
	};

	vector<int> ans(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		auto [id, ql, qr, p] = query[i];
		while(l > ql) add(seq[-- l]);
		while(r < qr) add(seq[++ r]);
		while(l < ql) add(seq[l ++]);
		while(r > qr) add(seq[r --]);
		if(p != -1) add(p);
		ans[id] = res;
		if(p != -1) add(p);
	}
	for(int i = 1; i <= m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
