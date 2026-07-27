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

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
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
		vector<int> deg(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);

			deg[u] ++, deg[v] ++;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			cnt += (deg[i] == 1);
		if(n == 1 || cnt == 2)
		{
			cout <<-1 <<endl;
			continue;
		}

		int r1, r2, c = 1;
		vector<int> dep(n + 1);
		vector<int> in(n + 1), out(n + 1); int cur = 1;
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			in[u] = cur ++;
			for(auto v : adj[u])
			{
				if(v == fa) continue;
				dep[v] = dep[u] + 1;
				if(dep[v] > dep[c]) c = v;
				self(v, u);
			}
			out[u] = cur;
		};
		dfs(1, -1); r1 = c;
		dep[c] = 0, cur = 1; dfs(c, -1), r2 = c;
		auto isAncester = [&](int u, int v) -> bool
		{
			return in[u] < in[v] && out[u] > in[v];
		};

		for(int u = 1; u <= n; u ++)
		{
			if(deg[u] >= 3 && isAncester(u, r2))
			{
				int l = -1, r = -1;
				for(auto v : adj[u])
				{
					if(dep[v] < dep[u]) l = v;
					else if(!isAncester(v, r2)) r = v;
				}
				cout <<l <<" " <<u <<" " <<r <<endl;
				break;
			}
		}
	}
	return 0;
}