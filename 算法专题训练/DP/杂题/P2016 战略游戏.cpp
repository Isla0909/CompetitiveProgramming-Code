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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> adj[n + 1];
	for(int i = 1; i <= n; i ++)
	{
		int a, k; cin >>a >>k;
		for(int j = 0; j < k; j ++)
		{
			int b; cin >>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	vector f(n + 1, vector<int>(2, INF));
	function <void(int, int)> dfs;
	dfs = [&](int u, int fa) -> void
	{
		f[u][0] = 0, f[u][1] = 1;
		for(auto v : adj[u])
		{
			if(v == fa) continue;

			dfs(v, u);
			f[u][1] += min(f[v][1], f[v][0]);
			f[u][0] += f[v][1];
		}
	};
	dfs(0, -1);
	cout <<min(f[0][0], f[0][1]) <<endl;
	return 0;
}