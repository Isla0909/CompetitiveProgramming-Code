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
		int n, m; cin >>n >>m;
		vector<int> a(n + 1), b(m + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= m; i ++) cin >>b[i];

		vector<int> f(m + 1, INF), g(m + 2);
		f[0] = 0, g[m + 1] = n + 1;
		for(int i = 1, j = 1; i <= m; i ++)
		{
			while(j <= n && a[j] < b[i]) j ++;
			if(j > n) break;
			f[i] = j ++;
		}
		for(int i = m, j = n; i >= 1; i --)
		{
			while(j >= 1 && a[j] < b[i]) j --;
			if(j < 1) break;
			g[i] = j --;
		}

		if(f[m] <= n)
		{
			cout <<0 <<endl;
			continue;
		}

		int ans = INF;
		for(int i = 1; i <= m; i ++)
		{
			if(f[i - 1] < g[i + 1])
				ans = min(ans, b[i]);
		}
		cout <<(ans == INF ? -1 : ans) <<endl;
	}
	return 0;
}