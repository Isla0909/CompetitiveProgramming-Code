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
		int s, e; cin >>s >>e;
		vector<int> adj[n + 1];
		for(int i = 1; i < n; i ++)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			adj[n].push_back(a);
		}
		vector<int> d(n + 1, INF); d[s] = 0;
		auto bfs = [&]() -> void
		{
			queue <int> q; q.push(s);
			while(q.size())
			{
				auto t = q.front(); q.pop();
				for(auto v : adj[t])
				{
					if(d[v] == INF)
					{
						d[v] = d[t] + 1;
						q.push(v);
					}
				}
			}
		};
		int dis = d[e] - d[s];
		int ans = dis / 2;
		
	}
	return 0;
}