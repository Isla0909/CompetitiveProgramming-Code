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

constexpr int N = 2e5 + 10, M = 1e6, INF = 0x3f3f3f3f, mod = 1e9 + 7;
 
signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, k; cin >>n >>m >>k;
	vector<bool> st(n + 1);
	for(int i = 0; i < k; i ++)
	{
		int x; cin >>x;
		st[x] = 1;
	}
	vector<int> adj[n + 1];
	while(m --)
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int root;
	for(int i = 1; i <= n; i ++)
		if(!st[i])
		{
			root = i;
			break;
		}
	vector<vector<int>> ans;
	vector<bool> vis(n + 1);
	auto bfs = [&]() -> void
	{
		queue<int> q;
		q.push(root); vis[root] = 1;
		while(q.size())
		{
			auto t = q.front(); q.pop();
			if(st[t]) continue;

			vector<int> p;
			for(auto v : adj[t])
			{
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;;
					p.push_back(v);
				}
			}
			if(p.size()) p.push_back(t);
			reverse(p.begin(), p.end());
			if(p.size()) ans.push_back(p);
		}
	};

	if(k != n) bfs();

	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		cnt += (vis[i]);
	if(cnt != n) cout <<"No" <<endl;
	else
	{
		cout <<"Yes" <<endl;
		cout <<ans.size() <<endl;

		for(auto v : ans)
		{
			cout <<v[0] <<" " <<v.size() - 1 <<" ";
			for(int i = 1; i < v.size(); i ++)
				cout <<v[i] <<" ";
			cout <<endl;
		}
	}
	return 0;
}