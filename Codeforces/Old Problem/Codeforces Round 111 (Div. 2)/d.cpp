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

struct cxy
{
	int u, v, w, id;
	cxy(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<cxy> edges;
	edges.reserve(m);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		edges.emplace_back(u, v, w, i);
	}
	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a.w < b.w;
	});

	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);

	auto find = [&](this auto &&self, int x) -> int
	{
		if(x != p[x]) p[x] = self(p[x]);
		return p[x];
	};

	auto merge = [&](int x, int y) -> void
	{
		x = find(x), y = find(y);
		if(x != y) p[x] = y;
	};

	vector<int> ans(m);

	for(int i = 0, j = 0; i < m; i = j)
	{
		while(j < m && edges[j].w == edges[i].w) j ++;

		vector<array<int, 3>> cur;
		for(int k = i; k < j; k ++)
		{
			auto [u, v, w, id] = edges[k];
			u = find(u), v = find(v);

			if(u == v) ans[id] = 0;
			else
			{
				ans[id] = 1;
				cur.push_back({u, v, id});
			}
		}

		vector<int> a;
		for(auto [u, v, id] : cur)
		{
			a.push_back(u);
			a.push_back(v);
		}

		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());

		auto get = [&](int x)
		{
			return lower_bound(a.begin(), a.end(), x) - a.begin();
		};

		int siz = a.size();
		vector<vector<pii>> adj(siz);
		vector<int> origin;
		for(auto [u, v, id] : cur)
		{
			u = get(u), v = get(v);
			int idx = origin.size();

			adj[u].emplace_back(v, idx);
			adj[v].emplace_back(u, idx);

			origin.push_back(id);
		}

		vector<int> dfn(siz, -1), low(siz, -1);
		int time_stamp = 0;
		auto tarjan = [&](this auto &self, int u, int from) -> void
		{
			dfn[u] = low[u] = time_stamp ++;

			for(auto [v, id] : adj[u])
			{
				if(id == from) continue;

				if(dfn[v] == -1)
				{
					self(v, id);
					low[u] = min(low[u], low[v]);

					if(low[v] > dfn[u]) ans[origin[id]] = 2;
				}
				else low[u] = min(low[u], dfn[v]);
			}
		};

		for(int u = 0; u < siz; u ++)
			if(dfn[u] == -1)
				tarjan(u, -1);

		for(int k = i; k < j; k ++)
			merge(edges[k].u, edges[k].v);
	}

	for(int i = 0; i < m; i ++)
	{
		if(!ans[i]) cout <<"none" <<endl;
		else if(ans[i] & 1) cout <<"at least one" <<endl;
		else cout <<"any" <<endl;
	}
	return 0;
}
