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

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<array<array<i64, 2>, 2>> f(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		f[u][0][0] = f[u][1][1] = 0;
		f[u][0][1] = -a[u], f[u][1][0] = a[u];

		for(auto v : adj[u])
		{
			if(v == fa) continue;

			self(v, u);
			array<array<i64, 2>, 2> ndp{-inf, -inf, -inf, -inf};
			for(int i = 0; i < 2; i ++)
			{
				for(int j = 0; j < 2; j ++)
				{
					ndp[i][j] = max(ndp[i][j], f[u][i][j] + f[v][1][1]);

				}
			}
		}
	};

	return 0;
}
