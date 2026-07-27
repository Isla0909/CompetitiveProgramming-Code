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

struct SparseTable
{
	int n, k;
	vector<vector<pii>> st;

	SparseTable() {}

	SparseTable(const vector<pii> &v)
	{
		initial(v);
	}

	void initial(const vector<pii> &v)
	{
		n = v.size() - 1;
		k = __lg(n) + 1;

		st.assign(k, vector<pii>(n + 1));

		for(int i = 1; i <= n; i ++)
			st[0][i] = v[i];
	}

	void min_work()
	{
		for(int j = 1; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
				st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}

	pii min_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return min(st[k][l], st[k][r - (1 << k) + 1]);
	}
};

struct Tree
{
	int n;
	vector<vector<pii>> adj;
	vector<pii> seq;

	vector<int> first;
	vector<int> dep;
	vector<i64> dist;

	SparseTable st;

	Tree(int n)
	{
		this->n = n;

		adj.resize(n + 1);
		first.resize(n + 1);
		dep.resize(n + 1);
		dist.resize(n + 1);

		seq.reserve(2 * n);
		seq.push_back({INF, 0});
	}

	void add(int u, int v, int w)
	{
		adj[u].emplace_back(v, w);
	}

	void dfs(int u, int fa)
	{
		first[u] = seq.size();
		seq.push_back({dep[u], u});

		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			dep[v] = dep[u] + 1;
			dist[v] = dist[u] + w;

			dfs(v, u);

			seq.push_back({dep[u], u});
		}
	}

	void work(int root = 1)
	{
		seq.push_back({INF, 0});

		dfs(root, 0);

		st.initial(seq);
		st.min_work();
	}

	int lca(int u, int v)
	{
		int l = first[u], r = first[v];
		return st.min_query(l, r).se;
	}

	i64 dis(int u, int v)
	{
		return dist[u] + dist[v] - 2 * dist[lca(u, v)];
	}
};

struct cxy
{
	int a, b;
	i64 d;

	cxy() {}
	cxy(int a, int b, i64 d) : a(a), b(b), d(d) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// freopen("mex.in", "r", stdin);
	// freopen("mex.out", "w", stdout);
	
	int n, q; cin >>n >>q;
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int w; cin >>w;
		if(w <= n) pos[w] = i;
	}

	Tree tr(n);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		tr.add(u, v, w), tr.add(v, u, w);
	}

	tr.work();

	int M = 0;
	while(M < n && pos[M]) M ++;

	vector<cxy> a(M);
	if(M)
	{
		a[0] = {pos[0], pos[0], 0};

		for(int i = 1; i < M; i ++)
		{
			int x = a[i - 1].a, y = a[i - 1].b, z = pos[i];

			i64 d0 = a[i - 1].d, d1 = tr.dis(x, z), d2 = tr.dis(y, z);

			if(d1 >= d0 && d1 >= d2) a[i] = {x, z, d1};
			else if(d2 >= d0 && d2 >= d1) a[i] = {y, z, d2};
			else a[i] = a[i - 1];
		}
	}

	while(q --)
	{
		int u; i64 k; cin >>u >>k;
		int l = -1, r = M;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;

			auto [x, y, d] = a[mid];
			if(tr.dis(u, x) <= k && tr.dis(u, y) <= k) l = mid;
			else r = mid;
		}
		cout <<r <<endl;
	}

	return 0;
}
