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

		vector<ll> pre(n + 1);
		for(int i = 1; i <= n; i ++)
			pre[i] = pre[i - 1] + a[i];

		vector<int> f(n + 1, INF); f[0] = 0;
		for(int i = 1; i <= m; i ++)
		{
			for(int r = 1, l = 0; r <= n; r ++)
			{
				while(l <= r && pre[r] - pre[l] > b[i]) l ++;
				f[r] = min(f[r], f[l] + m - i);
			}
		}
		cout <<(f[n] == INF ? -1 : f[n]) <<endl;
	}
	return 0;
}