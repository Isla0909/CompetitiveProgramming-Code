#pragma GCC optimize(2)
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

int p[12];

int getbit(int x, int c)
{
	return x / p[c] % 3;
}

struct cxy
{
	int s, e;
	int l, r;
	cxy(int s, int e, int l, int r) : s(s), e(e), l(l), r(r) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < 12; i ++)
		p[i] = p[i - 1] * 3;

	int n, m, q; cin >>n >>m >>q;
	vector<vector<int>> dis(n, vector<int>(n, INF));
	for(int i = 0; i < n; i ++)
		dis[i][i] = 0;

	for(int i = 0; i < m; i ++)
	{
		int u, v, w; cin >>u >>v >>w;
		u --, v --;
		dis[u][v] = min(dis[u][v], w);
	}

	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	vector<cxy> v;
	for(int i = 0; i < q; i ++)
	{
		int s, e, l, r; cin >>s >>e >>l >>r;
		s --, e --;
		v.emplace_back(s, e, l, r);
	}

	int mask = p[q];
	vector<int> cnt(mask);
	for(int s = 0; s < mask; s ++)
	{
		for(int j = 0; j < q; j ++)
			cnt[s] += (getbit(s, j) == 2);
	}

	vector<vector<int>> dp(mask, vector<int>(n, INF));
	dp[0][0] = 0;
	for(int s = 0; s < mask; s ++)
	{
		for(int u = 0; u < n; u ++)
		{
			if(dp[s][u] == INF) continue;

			for(int i = 0; i < q; i ++)
			{
				int status = getbit(s, i);
				if(status == 0)
				{
					int x = v[i].s;
					if(dis[u][x] == INF) continue;

					int val = dp[s][u] + dis[u][x];
					val = max(val, v[i].l);

					int ns = s + p[i];
					dp[ns][x] = min(dp[ns][x], val);
				}
				else if(status == 1)
				{
					int x = v[i].e;
					if(dis[u][x] == INF) continue;

					int val = dp[s][u] + dis[u][x];
					if(val > v[i].r) continue;

					int ns = s + p[i];
					dp[ns][x] = min(dp[ns][x], val);
				}
			}
		}
	}

	int ans = 0;
	for(int s = 0; s < mask; s ++)
		for(int j = 0; j < n; j ++)
			if(dp[s][j] != INF) ans = max(ans, cnt[s]);
	cout <<ans <<endl;
	return 0;
}
