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

int merge(int a, int b)
{
	int res = 0;
	for(int i = 0; i < 3; i ++)
		if(a >> i & 1)
		{
			for(int j = 0; j < 3; j ++)
				if(b >> j & 1) res |= (1 << ((i + j) % 3));
		}
	return res;
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
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> f(n + 1);
		auto dfs = [&](this auto&&self, int u, int fa) -> void
		{
			if(adj[u].size() == 1 && u != 1)
			{
				f[u] = 2;
				return ;
			}

			int cur = 1;
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
				cur = merge(cur, f[v]);
			}
			f[u] = cur | 2;
		};
		dfs(1, -1);
		cout <<(f[1] & 1 ? "YES" : "NO") <<endl;
	}
	return 0;
}
