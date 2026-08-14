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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i ++)
	{
		int u = i, v; cin >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	string s; cin >>s;
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++)
		w[i] = 1 << (s[i - 1] - 'a');

	vector<int> in(n + 1), dep(n + 1), seq(n + 1), siz(n + 1); int cur = 0;
	vector<vector<int>> vec(n + 1, {0});
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		in[u] = ++ cur, seq[in[u]] = u, siz[u] = 1;
		dep[u] = dep[fa] + 1;
		vec[dep[u]].push_back(in[u]);
		for(auto v : adj[u])
		{
			if(v == fa) continue; 
			self(v, u);
			siz[u] += siz[v];
		}
	};

	dfs(1, 0);

	vector<vector<int>> pre(n + 1);
	for(int h = 1; h <= n; h ++)
	{
		int m = vec[h].size();
		pre[h].resize(m);
		for(int i = 1; i < m; i ++)
			pre[h][i] = pre[h][i - 1] ^ w[seq[vec[h][i]]];
	}

	while(q --)
	{
		int u, h; cin >>u >>h;
		int l = in[u], r = in[u] + siz[u] - 1;

		l = lower_bound(vec[h].begin(), vec[h].end(), l) - vec[h].begin();
		r = upper_bound(vec[h].begin(), vec[h].end(), r) - vec[h].begin();
		if(l == r) cout <<"Yes" <<endl;
		else
		{
			r --;
			int mask = pre[h][r] ^ pre[h][l - 1];
			int c = __builtin_popcount(mask);
			cout <<(c <= 1 ? "Yes" : "No") <<endl;
		}
	}
	return 0;
}
