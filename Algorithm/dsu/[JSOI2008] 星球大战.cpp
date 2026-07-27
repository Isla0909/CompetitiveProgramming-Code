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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	int u, v, id;
	bool operator<(const cxy &T) const
	{
		return id < T.id;
	}
};

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
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);

	auto find = [&](this auto &&self, int x) -> i32
	{
		if(x != p[x]) p[x] = self(p[x]);
		return p[x];
	};

	vector<cxy> edges(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int u, v; cin >>u >>v;
		edges[i] = {u, v, 0};	
	}

	int k; cin >>k;
	vector<int> vis(n + 1);
	for(int i = 1; i <= k; i ++)
	{
		int x; cin >>x;
		vis[x] = k + 1 - i;
	}

	for(int i = 1; i <= m; i ++)
		edges[i].id = max(vis[edges[i].u], vis[edges[i].v]);

	sort(edges.begin() + 1, edges.end());

	int sum = n;
	auto merge = [&](int a, int b) -> void
	{
		int pa = find(a), pb = find(b);
		if(pa != pb)
		{
			p[pb] = pa;
			sum --;
		}
	};

	vector<int> ans(n + 1);
	for(int i = 0, j = 1; i <= k; i ++)
	{
		while(j <= m && edges[j].id <= i)
		{
			merge(edges[j].u, edges[j].v);
			j ++;
		}
		ans[i] = sum - (k - i);
	}
	for(int i = k; i >= 0; i --)
		cout <<ans[i] <<endl;
	return 0;
}