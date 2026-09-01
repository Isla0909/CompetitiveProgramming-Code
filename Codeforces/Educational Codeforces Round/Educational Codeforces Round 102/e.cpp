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
	vector<vector<pii>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<array<i64, 4>> f(n + 1);
	vector<array<bool, 4>> st(n + 1);
	for(int i = 1; i <= n; i ++)
		f[i].fill(inf);

	using T = tuple<i64, int, int>;
	priority_queue<T, vector<T>, greater<>> q;
	f[1][0] = 0;
	q.emplace(0, 1, 0);

	auto relax = [&](int v, int ns, i64 nd)
	{
		if(nd < f[v][ns])
		{
			f[v][ns] = nd;
			q.emplace(nd, v, ns);
		}
	};

	while(q.size())
	{
		auto [d, u, s] = q.top(); q.pop();

		if(st[u][s]) continue;
		st[u][s] = true;

		for(auto [v, w] : adj[u])
		{
			relax(v, s, d + w);

			if(!(s >> 0 & 1)) relax(v, s | 1, d);
			if(!(s >> 1 & 1)) relax(v, s | (1 << 1), d + 2 * w);
			if(!s) relax(v, 3, d + w);
		}
	}

	for(int i = 2; i <= n; i ++)
		cout <<f[i][3] <<" \n"[i == n];
	return 0;
}
