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

struct SpraseTable
{
	int n, k;
	vector<pii> a;
	vector<vector<pii>> st;

	SpraseTable() {}
	void initial(const vector<pii> &v)
	{
		n = v.size() - 1;
		k = __lg(n) + 1;

		a = v;
		st.assign(n + 1, vector<pii>(k));
	}

	void min_work()
	{
		for(int i = 1; i <= n; i ++)
			st[i][0] = a[i];

		for(int j = 1; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
				st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
	}

	pii min_query(int l, int r)
	{
		if(l > r) swap(l, r);

		int k = __lg(r - l + 1);
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

struct Tree
{
	int n;
	vector<vector<int>> adj;
	vector<pii> seq;

	vector<int> first;
	vector<int> dep;

	SpraseTable st;

	Tree(int n)
	{
		this -> n = n;

		adj.assign(n + 1, {});
		first.resize(n + 1);
		dep.resize(n + 1);

		seq.emplace_back(INF, 0);
	}

	void add(int u, int v)
	{
		adj[u].push_back(v);
	}

	void dfs(int u, int fa)
	{
		first[u] = seq.size();
		seq.emplace_back(dep[u], u);

		for(auto v : adj[u])
		{
			if(v == fa) continue;
			dep[v] = dep[u] + 1;

			dfs(v, u);
			seq.emplace_back(dep[u], u);
		}
	}

	void work(int root = 1)
	{
		seq.emplace_back(INF, 0);
		dfs(root, 0);

		st.initial(seq);
		st.min_work();
	}

	int lca(int a, int b)
	{
		int l = first[a], r = first[b];
		return st.min_query(l, r).se;
	}

	int dis(int a, int b)
	{
		return dep[a] + dep[b] - 2 * dep[lca(a, b)];
	}
};

struct cxy
{
	int a, b, d;
	cxy() {}
	cxy(int a, int b, int d) : a(a), b(b), d(d) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	string s; cin >>s;

	vector<int> col(n + 1);
	for(int i = 1; i <= n; i ++)
		col[i] = s[i - 1] - '0';
	Tree tr(n);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		tr.add(u, v), tr.add(v, u);
	}

	tr.work();

	int a = -1, b = -1, d = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(!col[i]) continue;

		if(a == -1)
		{
			a = b = i;
			continue;
		}

		int da = tr.dis(i, a), db = tr.dis(i, b);

		if(da > d)
		{
			b = i;
			d = da;
		}
		else if(db > d)
		{
			a = i;
			d = db;
		}
	}
	for(int i = 1; i <= n; i ++)
		cout <<max({d, tr.dis(i, a), tr.dis(i, b)}) <<endl;
	return 0;
}
