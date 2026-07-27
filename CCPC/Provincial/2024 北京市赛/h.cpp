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
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i ++)
	{
		int p; cin >>p;
		adj[i].push_back(p);
		adj[p].push_back(i);
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
	int q; cin >>q;
	while(q --)
	{
		int m; cin >>m;
		vector<int> a(m + 1);
		for(int i = 1; i <= m; i ++) cin >>a[i];
		bool f = 1;
		for(int i = 2; i <= m; i ++)
			if(dep[a[i]] < dep[a[i - 1]])
			{
				f = 0;
				break;
			}
		cout <<(f ? "Yes" : "No") <<endl;
	}

	return 0;
}
