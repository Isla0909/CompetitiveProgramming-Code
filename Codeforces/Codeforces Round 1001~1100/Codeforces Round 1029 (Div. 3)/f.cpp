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

i64 p[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < N; i ++)
		p[i] = p[i - 1] * 2LL % mod;

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int cnt = 0, lca = 1;
		vector<int> v;
		for(int u = 2; u <= n; u ++)
		{
			if(adj[u].size() == 1) 
			{
				cnt ++;
				v.push_back(u);
			}
			if(adj[u].size() == 3) lca = u;
		}

		if(cnt > 2)
		{
			cout <<0 <<endl;
			continue;
		}
		if(cnt == 1)
		{
			cout <<p[n] <<endl;
			continue;
		}
		
		vector<int> dep(n + 1);
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				dep[v] = dep[u] + 1;

				self(v, u);
			}
		};
		dfs(1, -1);

		int len = dep[lca] - dep[1] + 1;
		int x = v[0], y = v[1];
		int d1 = dep[x] - dep[lca], d2 = dep[y] - dep[lca];
		i64 ans = 0;
		//cout <<x <<" " <<d1 <<" " <<y <<" " <<d2 <<endl;
		if(d1 <= d2)
		{
			//x = 1, y = 2
			ans += p[len] * p[d2 - d1] % mod;
			ans %= mod;

			//x = 2, y = 1
			ans += p[len] * p[max(0, d2 - (d1 + 1))] % mod;
			ans %= mod;
		}
		else//d1 > d2
		{
			//x = 1, y = 2
			ans += p[len] * p[d1 - d2 - 1];
			ans %= mod;

			//x = 2, y = 1;
			ans += p[len] * p[d1 - d2] % mod;
			ans %= mod;
		}
		cout <<ans <<endl;
	}
	return 0;
}
