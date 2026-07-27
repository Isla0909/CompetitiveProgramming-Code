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

	int n, m; cin >>n >>m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> st(n + 1);
	vector<int> d(n + 1, INF), cnt(n + 1);
	queue<int> q;
	q.emplace(1); st[1] = 1; cnt[1] = 1; d[1] = 0;
	while(q.size())
	{
		auto u = q.front(); q.pop(); st[u] = 0;
		for(auto v : adj[u])
		{
			if(d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
				cnt[v] = cnt[u];
				if(!st[v])
				{
					q.emplace(v);
					st[v] = 1;
				}
			}
			else if(d[v] == d[u] + 1) cnt[v] = (cnt[v] + cnt[u]) % mod;
		}
	}
	cout <<cnt[n] <<endl;
	return 0;
}
