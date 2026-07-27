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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
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
		vector p(3, vector<int>(n));
		vector rank(3, vector<int>(n));
		for(int i = 0; i < 3; i ++)
			for(int j = 0; j < n; j ++)
			{
				cin >>p[i][j];
				p[i][j] --;
				rank[i][p[i][j]] = j + 1;
			}
		vector<pii> adj[n + 1];
		for(int i = 0; i < 3; i ++)
		{
			for(int j = n - 1; j - 1 >= 0; j --)
			{
				adj[rank[i][j]].emplace_back(rank[i][j - 1], i);
				cout <<rank[i][j] <<" " <<rank[i][j - 1] <<" ";
			}
			cout <<endl;
		}
		vector<pii> pre(n + 1, {-1, -1});
		vector<pii> ans;

		auto bfs = [&]() -> void
		{
			queue<int> q; q.emplace(1);
			while(q.size())
			{
				auto t = q.front(); q.pop();
				for(auto [v, fa] : adj[t])
				{
					if(pre[v].ff != -1 && v != 1) continue;
					cout <<v <<" " <<fa <<" " <<t <<endl;
					pre[v].ff = t, pre[v].se = fa;
					q.push(v);
				}
			}
		};
		bfs();
		if(pre[n].ff == -1) cout <<"NO" <<endl;
		else
		{
			cout <<"YES" <<endl;
			// int x = n;
			// while(pre[x].ff != -1)
			// {
			// 	ans.emplace_back(pre[x].se, pre[x].ff);
			// 	x = pre[x].ff;
			// }
			// reverse(ans.begin(), ans.end());
			// cout <<ans.size() <<endl;
			// for(auto c : ans)
			// 	cout <<"qkj"[c.ff] <<" " <<c.se <<endl;
		}
	}
	return 0;
}