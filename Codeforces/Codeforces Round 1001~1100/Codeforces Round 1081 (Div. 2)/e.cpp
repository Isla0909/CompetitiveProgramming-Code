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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1);
		vector<int> cnt(n + 1);
		for(int i = 1; i <= n; i ++) 
		{
			cin >>a[i];
			cnt[a[i]] ++;
		}
		for(int i = 1; i <= n; i ++) 
		{
			cin >>b[i];
			cnt[b[i]] ++;
		}

		bool f = 1;
		for(int i = 1; i <= n; i ++)
			if(cnt[i] & 1)
			{
				f = 0;
				break;
			}
		if(!f)
		{
			cout <<-1 <<endl;
			continue;
		}

		vector<vector<pii>> adj(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int u = a[i], v = b[i];
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
		}

		vector<int> used(n + 1), from(n + 1), it(n + 1);
		auto dfs = [&](this auto &&self, int u) -> void
		{
			while(it[u] < adj[u].size())
			{
				auto [v, id] = adj[u][it[u]];
				it[u] ++;
				if(used[id]) continue;
				used[id] = 1;
				from[id] = v;
				self(v);
			}
		};

		for(int i = 1; i <= n; i ++)
		{
			while(it[i] < adj[i].size() && used[ adj[i][it[i]].se ]) it[i] ++;
			if(it[i] == adj[i].size()) continue;

			dfs(i);
		}

		vector<int> ans;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == b[i]) continue;
			if(from[i] == b[i]) ans.push_back(i);
		}

		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
