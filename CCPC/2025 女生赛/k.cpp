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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 f[N];

void initial()
{
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i ++)
		f[i] = f[i - 1] * i % mod;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i ++)
	{
		int x; cin >>x;
		adj[x].push_back(i);
	}

	vector<int> siz(n + 1);
	i64 min = 0, ans = 1;
	auto dfs = [&](this auto &&self, int u) -> void
	{
		siz[u] = 1;
		for(auto v : adj[u])
		{
			self(v);
			siz[u] += siz[v];
		}
		
		ranges::sort(adj[u].begin(), adj[u].end(), [&](int a, int b)
		{
			return siz[a] > siz[b];
		});

		const int m = adj[u].size();
		int i = 0, j = 0;
		while(i < m)
		{
			while(j < m && siz[adj[u][i]] == siz[adj[u][j]]) j ++;
			ans = ans * f[j - i] % mod;
			i = j;
		}
		for(int i = m - 1; i > 0; i --)
			siz[adj[u][i - 1]] += siz[adj[u][i]];
	};
	dfs(1);
	cout <<accumulate(siz.begin(), siz.end(), 0LL) <<endl;
	cout <<ans <<endl;
	return 0;
}
