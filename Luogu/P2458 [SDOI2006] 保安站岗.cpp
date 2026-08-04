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

	int n; cin >>n;
	vector<int> w(n + 1);
	vector<vector<int>> adj(n + 1);
	vector<bool> st(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int id; cin >>id;
		cin >>w[id];

		int m; cin >>m;
		for(int j = 0; j < m; j ++)
		{
			int v; cin >>v;
			st[v] = 1;
			adj[id].push_back(v);
			adj[v].push_back(id);
		}
	}

	int root = 1;
	while(root <= n && st[root]) root ++;

	/*
		f[u][0]：u 自己放侍卫
		f[u][1]：u 被某个儿子看守
		f[u][2]：u 留给父亲看守
	*/ 
	vector<array<i64, 3>> f(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		f[u][0] = w[u];
		f[u][1] = INF, f[u][2] = 0;

		i64 val = inf;
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);

			f[u][0] += min({f[v][0], f[v][1], f[v][2]});

			f[u][2] += min(f[v][0], f[v][1]);

			val = min(val, f[v][0] - min(f[v][0], f[v][1]));
		}
		if(val != inf) f[u][1] = f[u][2] + val;
	};
	dfs(root, -1);
	cout <<min(f[root][0], f[root][1]) <<endl;
	return 0;
}
	