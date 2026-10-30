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

struct DSU
{
	vector<int> p, siz;
	vector<array<int, 3>> stk;

	DSU(int n)
	{
		p.assign(n + 1, {});
		siz.assign(n + 1, 1);
		iota(p.begin(), p.end(), 0);
	}

	int find(int x)
	{
		while(x != p[x]) x = p[x];
		return x;
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if(x == y) return ;

		if(siz[x] > siz[y]) swap(x, y);

		stk.push_back({x, y, siz[y]});
		p[x] = y;
		siz[y] += siz[x];
	}

	int snapshot()
	{
		return stk.size();
	}

	void rollback(int t)
	{
		while(stk.size() > t)
		{
			auto [x, y, old] = stk.back();
			stk.pop_back();

			p[x] = x;
			siz[y] = old;
		}
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;;
	vector<int> op(m + 1), a(m + 1), b(m + 1), ans(m + 1);
	vector<vector<int>> adj(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		cin >>op[i];
		if(op[i] == 2)
		{
			int k; cin >>k;
			adj[k].push_back(i);
		}
		else
		{
			cin >>a[i] >>b[i];
			adj[i - 1].push_back(i);
		}
	}

	DSU dsu(n);
	[&](this auto &&self, int u) -> void
	{
		int t = dsu.snapshot();

		if(op[u] == 1) dsu.merge(a[u], b[u]);
		else if(op[u] == 3) ans[u] = dsu.same(a[u], b[u]);

		for(auto v : adj[u])
			self(v);

		dsu.rollback(t);
	}(0);

	for(int i = 1; i <= m; i ++)
		if(op[i] == 3) cout <<ans[i] <<endl;

	return 0;
}
