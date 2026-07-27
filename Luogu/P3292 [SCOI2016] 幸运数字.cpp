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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

struct LinearBasis
{
	static constexpr int BASE = 61;
	vector<i64> d;

	LinearBasis()
	{
		d.assign(BASE, 0);
	}

	void insert(i64 x)
	{
		for(int i = BASE - 1; i >= 0; i --)
			if(x >> i & 1LL)
			{
				if(!d[i])
				{
					d[i] = x;
					return ;
				}
				x ^= d[i];
			}
	}

	i64 getmax()
	{
		i64 res = 0;
		for(int i = BASE - 1; i >= 0; i --)
			if((res ^ d[i]) > res) res ^= d[i];
		return res;
	}
};

LinearBasis merge(const LinearBasis &a, const LinearBasis &b)
{
	LinearBasis c = a;
	for(int i = a.BASE - 1; i >= 0; i --)
		if(b.d[i]) c.insert(b.d[i]);
	return c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int len = 16;
	vector<int> dep(n + 1);
	vector f(n + 1, vector<int>(len));
	vector base(n + 1, vector<LinearBasis>(len));
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		dep[u] = dep[fa] + 1;
		f[u][0] = fa; base[u][0].insert(a[u]);

		for(int k = 1; k < len; k ++)
		{
			f[u][k] = f[f[u][k - 1]][k - 1];
			base[u][k] = merge(base[u][k - 1], base[f[u][k - 1]][k - 1]);
		}

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
		}
	};

	auto query = [&](int x, int y) -> i64
	{
		LinearBasis ans;
		if(dep[x] < dep[y]) swap(x, y);

		for(int k = len - 1; k >= 0; k --)
			if(dep[f[x][k]] >= dep[y])
			{
				ans = merge(ans, base[x][k]);
				x = f[x][k];
			}

		if(x == y)
		{
			ans.insert(a[x]);
			return ans.getmax();
		}

		for(int k = len - 1; k >= 0; k --)
		{
			if(f[x][k] != f[y][k])
			{
				ans = merge(ans, base[x][k]);
				ans = merge(ans, base[y][k]);
				x = f[x][k];
				y = f[y][k];
			}
		}
		int p = f[x][0];
		ans.insert(a[x]), ans.insert(a[y]), ans.insert(a[p]);
		return ans.getmax();
	};
	dfs(1, 0);

	while(q --)
	{
		int u, v; cin >>u >>v;
		cout <<query(u, v) <<endl;
	}

	return 0;
}
