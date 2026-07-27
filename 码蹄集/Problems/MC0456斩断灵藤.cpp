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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> siz(n + 1), fa(n + 1); 
	fa[1] = -1; int ans = 0;
	auto dfs = [&](auto &&self, int u) -> void
	{
		if(fa[u] != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa[u]));

		siz[u] = 1;
		vector<int> a;
		for(auto v : adj[u])
		{
			fa[v] = u;

			self(self, v);

			a.push_back(siz[v]);
		}
		sort(a.begin(), a.end());
		int s = accumulate(a.begin(), a.end(), 0) + 1;
		while(s > m)
		{
			ans ++;
			s -= a.back(); a.pop_back();
		}
		siz[u] = s;
	};
	dfs(dfs, 1);
	cout <<ans + 1 <<endl;
	return 0;
}
