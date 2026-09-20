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

struct DSU
{
    vector<int> p, siz;

    void initial(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void merge(int a, int b)
    {
        a = find(a), b = find(b);
        if(a == b) return;
        if(siz[a] < siz[b]) swap(a, b);
        p[b] = a;
        siz[a] += siz[b];
    }
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> cost(n + 1);
	for(int i = 1; i <= n; i ++) cin >>cost[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> l(n + 1), r(n + 1); int cnt = 0;
	[&](this auto &&self, int u, int fa) -> void
	{
		l[u] = cnt + 1;

		if(u != 1 && adj[u].size() == 1) cnt ++;

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			self(v, u);
		}
		r[u] = cnt;
	}(1, 0);

	vector<array<int, 4>> edges;
	for(int i = 1; i <= n; i ++)
		edges.push_back({l[i], r[i] + 1, cost[i], i});

	sort(edges.begin(), edges.end(), [&](const auto &a, const auto &b)
	{
		return a[2] < b[2];
	});

	DSU dsu;
	dsu.initial(cnt + 1);
	vector<int> ok(n + 1);
	i64 ans = 0;

	for(int i = 0; i < n; )
	{
		int j = i;
		while(j < n && edges[j][2] == edges[i][2]) j ++;

		for(int k = i; k < j; k ++)
		{
			auto [u, v, w, id] = edges[k];
			if(!dsu.same(u, v)) ok[id] = 1;
		}

		for(int k = i; k < j; k ++)
		{
			auto [u, v, w, id] = edges[k];
			if(dsu.same(u, v)) continue;

			dsu.merge(u, v);
			ans += w;
		}

		i = j;
	}
	int k = count(ok.begin() + 1, ok.end(), 1);
	cout <<ans <<" " <<k <<endl;

	for(int i = 1; i <= n; i ++)
		if(ok[i]) cout <<i <<" ";
	cout <<endl;
	return 0;
}
