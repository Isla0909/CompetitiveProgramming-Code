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

struct cxy
{
	int l, r;
	int c;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<cxy> bus(m); vector<int> a;
		for(int i = 0; i < m; i ++)
		{
			int l, r, c; cin >>l >>r >>c;
			bus[i] = {l, r, c};
			a.push_back(l), a.push_back(r);
		}
		a.push_back(n);
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());

		auto find = [&](int x) -> int
		{
			return lower_bound(a.begin(), a.end(), x) - a.begin();
		};

		vector<pii> adj[2 * m + 1];
		for(int i = 0; i < m; i ++)
		{
			int u = find(bus[i].l), v = find(bus[i].r), w = bus[i].c;
			//cout <<u <<" " <<v <<" " <<w <<endl;
			adj[u].emplace_back(v, w);
			for(int j = v - 1; j > u; j --)
				adj[v].emplace_back(j, 0);
		}
		vector<int> dist(2 * m + 1, 0);
		vector<bool> st(2 * m + 1, 0);
		auto spfa = [&]() -> void
		{
			queue<int> q;
			dist[0] = INF; q.push(0); st[0] = 1;
			while(q.size())
			{
				auto u = q.front(); q.pop(); st[u] = 0;
				for(auto [v, w] : adj[u])
				{
					//cout <<u <<" " <<v <<" " <<w <<endl;
					if(!w) dist[v] += dist[u], dist[u] = 0;
					else 
				}
			}
		};
		spfa();
		//cout <<find(n) <<endl;
		cout <<dist[find(n)] <<endl;
	}
	return 0;
}