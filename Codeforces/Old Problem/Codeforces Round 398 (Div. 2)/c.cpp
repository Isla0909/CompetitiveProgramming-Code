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
	vector<int> fa(n + 1), t(n + 1); int tot = 0;
	for(int u = 1; u <= n; u ++)
	{
		int p, x; cin >>p >>x;
		adj[p].push_back(u);
		fa[u] = p; t[u] = x;
		tot += x;
	}

	if(tot % 3 != 0)
	{
		cout <<-1 <<endl;
		return 0;
	}

	int tar = tot / 3;

	int root = 1;
	while(fa[root] != 0) root ++;

	vector<int> in(n + 1), out(n + 1), seq(n + 1); int cur = 1;
	vector<int> sum(n + 1), siz(n + 1);
	vector<pii> seg;
	int first = INF, last = -INF;
	[&](this auto &&self, int u) -> void
	{
		in[u] = cur ++;
		seq[in[u]] = u;
		siz[u] = 1, sum[u] = t[u];
		for(auto v : adj[u])
		{
			self(v);
			siz[u] += siz[v];
			sum[u] += sum[v];
		}
		out[u] = cur;
		if(sum[u] == tar) seg.emplace_back(in[u], in[u] + siz[u] - 1);
	}(root);

	auto isAncestor = [&](int u, int v)
	{
		return in[u] <= in[v] && out[u] > in[v];
	};

	int x = -1, y = -1;
	for(auto [l, r] : seg)
	{
		if(r < first)
		{
			first = r;
			x = seq[l];
		}
		if(l > last)
		{
			last = l;
			y = seq[l];
		}
	}
	if(first < last) 
	{
		cout <<x <<" " <<y <<endl;
		return 0;
	}
	
	int v = -1;
	for(int i = n; i >= 1; i --)
	{
		int u = seq[i];
		if(u != root && sum[u] == 2 * tar && v != -1 && isAncestor(u, v))
		{
			cout <<u <<" " <<v <<endl;
			return 0;
		}
		if(sum[u] == tar) v = u;
	}
	cout <<-1 <<endl;
	return 0;
}
