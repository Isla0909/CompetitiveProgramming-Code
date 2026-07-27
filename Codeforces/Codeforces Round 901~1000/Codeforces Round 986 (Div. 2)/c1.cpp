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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, v; cin >>n >>m >>v;
		vector<int> a(n + 1); vector<ll> pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
		}
		vector<int> f(m + 1), g(m + 1);
		f[0] = 0;
		for(int i = 1, j = 1; i <= m; i ++)
		{
			while(j <= n && pre[j] - pre[f[i - 1]] < v) j ++;
			f[i] = j;
		}
		g[0] = n + 1;
		for(int i = 1, j = n; i <= m; i ++)
		{
			while(j >= 0 && pre[g[i - 1] - 1] - pre[j] < v) j --;
			g[i] = j + 1;
		}
		//tell(0, f), tell(0, g);
		ll ans = -1;
		for(int i = 0; i <= m; i ++)
		{
			if(f[i] < g[m - i])
				ans = max(ans, pre[g[m - i] - 1] - pre[f[i]]);
		}
		cout <<ans <<endl;
	}
	return 0;
}