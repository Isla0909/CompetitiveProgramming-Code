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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<pii> a(n), b(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>a[i].ff;
			a[i].se = i + 1;
		}
		for(int i = 0; i < n; i ++)
		{
			cin >>b[i].ff;
			b[i].se = i + 1;
		}

		sort(a.begin(), a.end(), greater<pii>()), sort(b.begin(), b.end(), greater<pii>());

		vector<int> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			adj[a[i].se].push_back(a[i - 1].se);
			adj[b[i].se].push_back(b[i - 1].se);
		}

		int e, m = -1;
		for(int i = 0; i < n; i ++)
			if(a[i].ff > m)
			{
				m = a[i].ff;
				e = a[i].se;
			}
		vector<int> st(n + 1); st[e] = 1;
		function <void(int)> dfs = [&](int u) -> void
		{
			for(auto v : adj[u])
			{
				if(!st[v])
				{
					st[v] = 1;
					dfs(v);
				}
			}
		};
		dfs(e);
		for(int i = 1; i <= n; i ++)
			cout <<st[i];
		cout <<endl;
	}
	return 0;
}