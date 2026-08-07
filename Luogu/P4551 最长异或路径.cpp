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

constexpr int N = 1e5 + 10, M = 31 * N, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int trie[M][2];
int tot;

int newNode()
{
	tot ++;
	trie[tot][0] = trie[tot][1] = 0;
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

void insert(int x)
{
	int p = 1;
	for(int i = 30; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(!trie[p][d]) trie[p][d] = newNode();
		p = trie[p][d];
	}
}

int query(int x)
{
	int p = 1, res = 0;
	for(int i = 30; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(trie[p][d ^ 1])
		{
			res |= 1 << i;
			p = trie[p][d ^ 1];
		}
		else p = trie[p][d];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	vector<vector<pii>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	vector<int> dist(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			dist[v] = dist[u] ^ w;
			self(v, u);
		}
	};
	dfs(1, 0);

	for(int i = 1; i <= n; i ++)
		insert(dist[i]);

	int ans = 0;
	for(int i = 1; i <= n; i ++)		
		ans = max(ans, query(dist[i]));
	cout <<ans <<endl;
	return 0;
}
