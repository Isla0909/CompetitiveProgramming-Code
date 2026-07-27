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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++) cin >>b[i];
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<i64> sum1(n + 1), sum2(n + 1);
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			if(fa != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), fa));

			sum1[u] = a[u], sum2[u] = b[u];
			for(auto v : adj[u])
			{
				self(v, u);
				sum1[u] += sum1[v], sum2[u] += sum2[v];
			}
			if(adj[u].size() > (u32)1) sort(adj[u].begin(), adj[u].end(), [&](const auto &x, const auto &y) { return sum1[x] * sum2[y] > sum1[y] * sum2[x]; });
		};

		dfs(1, -1);
		i64 ans = 0, pre = sum2[1];
		auto calc = [&](this auto &&self, int u) -> void
		{
			pre -= b[u];
			ans += a[u] * pre;
			for(auto v : adj[u])
				self(v);
		};
		calc(1);
		cout <<ans <<endl;
	}
	return 0;
}
