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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct DSU
{
	vector<int> p, siz;
	int cnt, d;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 0);
		cnt = 0;
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

		if(siz[a] >= d && siz[b] >= d) cnt --;
		else if(siz[a] < d && siz[b] < d && siz[a] + siz[b] >= d) cnt ++;

		p[b] = a;
		siz[a] += siz[b];
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

	int n, m, x, d; cin >>n >>m >>x >>d;
	vector<int> h(n + 1), v(n + 1);
	for(int i = 1; i <= n; i ++) cin >>h[i];

	iota(v.begin(), v.end(), 0); 

	sort(v.begin() + 1, v.end(), [&](int i, int j)
	{
		return h[i] > h[j];
	});

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> H(x + 1);
	for(int i = 1; i <= x; i ++) cin >>H[i];

	DSU dsu(n); dsu.d = d;
	vector<int> ans(x + 1), st(n + 1); 
	int j = 0;
	for(int i = x; i >= 1; i --)
	{
		while(j + 1 <= n && h[v[j + 1]] > H[i])
		{
			j ++;
			int u = v[j]; st[u] = 1;
			dsu.siz[u] = 1;
			if(d == 1) dsu.cnt ++;
			//cout <<i <<" " <<u <<endl;
			for(auto v : adj[u])
			{
				if(!st[v]) continue;
				//if(dsu.same(u, v)) continue;
				//cout <<v <<" v and u " <<u <<endl;
				//cout <<dsu.size(v) <<" " <<dsu.size(u) <<endl;
				dsu.merge(v, u);
				//cout <<i <<" i and cnt " <<dsu.cnt <<endl;
			}
		}
		ans[i] = dsu.cnt;
		//cout <<i <<" i and cnt " <<ans[i] <<endl;
	}
	for(int i = 1; i <= x; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
