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

int query(int u, int k)
{
	cout <<"? " <<u <<" " <<k <<endl;
	int x; cin >>x;
	if(x == -1) exit(0);
	return x;
}

int rand(int l, int r)
{
	return l + rng() % (r - l + 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> adj(n + 1);
		for(int i = 2; i <= n; i ++)
		{
			int fa; cin >>fa;
			adj[i].push_back(fa);
			adj[fa].push_back(i);
		}

		vector<int> dep(n + 1); int len = __lg(2 * n - 1);
		vector f(n + 1, vector<int>(len));
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			f[u][0] = fa;
			dep[u] = dep[fa] + 1;

			for(int k = 1; k < len; k ++)
				f[u][k] = f[f[u][k - 1]][k - 1];

			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
			}
		};
		dfs(1, 0);

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

		auto dis = [&](int a, int b) -> int
		{
			return dep[a] + dep[b] - 2 * dep[lca(a, b)];
		};

		vector<int> s;
		for(int i = 1; i <= n; i ++)
			s.push_back(i);
		while(s.size() != 1)
		{
			if(s.size() == 2)
			{
				int a = s[0], b = s[1];
				if(query(a, 0)) break;
				else swap(s[0], s[1]);
				continue;
			}

			int l = 0, r = s.size() - 1;
			int u = rand(l, r); u = s[u];
			vector<int> d;
			for(auto v : s)
				d.push_back(dis(u, v));
			sort(d.begin(), d.end());
			int m = d.size();
			int k = d[(m - 1) / 2];
			int cnt = upper_bound(d.begin(), d.end(), k) - d.begin();
			if(cnt == m) k = d.back() - 1;
			vector<int> ns;
			if(query(u, k))
			{
				for(auto v : s)
					if(dis(u, v) <= k) ns.push_back(v);
			}
			else
			{
				for(auto v : s)
					if(dis(u, v) > k) ns.push_back(v);
			}
			s = ns;
		}
		cout <<"! " <<s[0] <<endl;
	}
	return 0;
}
