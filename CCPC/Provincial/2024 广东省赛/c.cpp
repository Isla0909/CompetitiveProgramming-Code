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
	vector<i64> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >>w[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i ++)
	{
		int p; cin >>p;
		adj[p].push_back(i);
	}

	vector<i64> siz(n + 1), sum(n + 1);
	auto dfs = [&](this auto &&self, int u) -> void
	{
		siz[u] = 1, sum[u] = w[u];
		for(auto v : adj[u])
		{
			self(v);
			siz[u] += siz[v], sum[u] += sum[v];
		}

		sort(adj[u].begin(), adj[u].end(), [&](int i, int j)
		{
			return siz[i] * sum[j] > siz[j] * sum[i];
		});
	};

	dfs(1);

	i64 ans = 0; int cur = 1;
	auto calc = [&](this auto &&self, int u) -> void
	{
		ans += w[u] * cur;
		cur ++;
		for(auto v : adj[u])
			self(v);
	};
	calc(1);
	cout <<ans <<endl;
	return 0;
}
