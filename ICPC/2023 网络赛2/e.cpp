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

struct DSU
{
	vector<int> p, siz;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);
	}

	DSU(int n)
	{
		initial(n);
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
		if(a == b) return ;

		siz[a] += siz[b];
		p[b] = a;
	}

	int size(int x)
	{
		return siz[find(x)];
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> fa(n + 1);
	for(int i = 2; i <= n; i ++) cin >>fa[i];

	vector<vector<int>> adj(n + 1);
	while(m --)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu(n);
	vector<int> d(n + 1, -1); d[1] = 0; 
	queue<int> q; q.push(1);
	while(!q.empty())
	{
		auto u = q.front(); q.pop();
		for(auto v : adj[u])
		{
			while(dsu.find(v) != 1)
			{
				dsu.merge(1, v);
				d[v] = d[u] + 1;
				q.push(v);
				v = fa[v];
			}
		}
	}
	tell(2, d);
	return 0;
}