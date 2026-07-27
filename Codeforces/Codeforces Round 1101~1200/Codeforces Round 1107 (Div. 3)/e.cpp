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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

bool ok[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 1; i < N; i ++)
	{
		int c = sqrt(i);
		if(c * c == i) ok[i] = 1;
	}

	int T; cin >>T;
	while(T --)
	{
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

		vector<int> siz(n + 1), fa(n + 1);
		auto dfs = [&](this auto &&self, int u, int p) -> void
		{
			siz[u] = 1;
			fa[u] = p;
			for(auto v : adj[u])
			{
				if(v == p) continue;

				self(v, u);
				siz[u] += siz[v];
			}
		};
		dfs(1, -1);

		i64 ans = 0;
		for(int u = 1; u <= n; u ++)
		{
			if(!ok[a[u]]) continue;

			i64 sum1 = 0, sum2 = 0, sum3 = 0;
			int x;
			for(auto v : adj[u])
			{
				if(u == fa[v]) x = siz[v];
				else x = n - siz[u];

				sum3 += sum2 * x;
				sum2 += sum1 * x;
				sum1 += x;
			}

			ans += sum2 + sum3;
		}
		cout <<ans <<endl;
	}
	return 0;
}
