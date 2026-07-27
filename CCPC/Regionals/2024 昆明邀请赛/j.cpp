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

struct SparseTable
{
	int n, k;
	vector<int> a;
	vector<vector<int>> st;

	SparseTable() {}
	SparseTable(vector<int> &v)
	{
		initial(v);
	}

	void initial(vector<int> &v)
	{
		n = v.size() - 1;
		k = __lg(2 * n - 1) + 1;
		a.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			a[i] = v[i];
		st.assign(n + 1, vector<int>(k));
	}

	void max_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int max_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void min_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int min_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void gcd_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int gcd_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector<vector<array<int, 3>>> adj(n + 1);
		for(int i = 1; i <= m; i ++)
		{
			int u, v, c, w; cin >>u >>v >>c >>w;
			adj[u].push_back({v, c, w});
			adj[v].push_back({u, c, w});
		}

		vector<vector<int>> pos(m + 1), len(m + 1, {0});	
		vector<int> l(k + 1), col(k + 1);
		for(int i = 1; i <= k; i ++)
		{
			int c, s; cin >>c >>s;
			pos[c].push_back(i);
			len[c].push_back(s);
			col[i] = c, l[i] = s;
		}

		vector<SparseTable> f(m + 1);
		for(int i = 1; i <= m; i ++)
		{
			if(!pos[i].size()) continue;
			f[i].initial(len[i]);
			f[i].max_work();
		}

		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
		q.push({0, 0, 1});
		vector<bool> vis(n + 1);
		while(!q.empty())
		{
			auto [p, s, u] = q.top(); q.pop();
			//cout <<p <<" " <<s <<" " <<u <<endl;
			if(vis[u]) continue;
			vis[u] = 1;

			for(auto [v, c, w] : adj[u])
			{
				if(vis[v] || pos[c].empty()) continue;
				if(c == col[p] && s + w <= l[p])//一张车票继续用
				{
					q.push({p, s + w, v});
					//if(v == 3) cout <<p <<" " <<s <<" " <<u <<endl;
					continue;
				}
				//cout <<p <<endl;
				auto it = upper_bound(pos[c].begin(), pos[c].end(), p);//换车票
				if(it == pos[c].end()) continue;

				int left = it - pos[c].begin() + 1;
				int lo = left, hi = len[c].size() - 1;
				//cout <<lo <<" " <<hi <<endl;
				if(f[c].max_query(lo, hi) < w) continue;
				while(lo < hi)
				{
					int mid = lo + hi >> 1;
					if(f[c].max_query(left, mid) >= w) hi = mid;
					else lo = mid + 1;
				}
				//cout <<"lo " <<lo <<endl;
				q.push({pos[c][lo - 1], w, v});
				//if(v == 3) cout <<p <<" " <<s <<" " <<u <<endl;
			}
		}
		for(int i = 1; i <= n; i ++)
			cout <<vis[i];
		cout <<endl;
	}
	return 0;
}