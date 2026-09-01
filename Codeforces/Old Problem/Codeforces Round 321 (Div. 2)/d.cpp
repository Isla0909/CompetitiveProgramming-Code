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

	int n, m, k; cin >>n >>m >>k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) cin >>a[i];

	vector f(n, vector<i64>(1 << n, -inf));
	for(int i = 0; i < n; i ++)
		f[i][1 << i] = a[i];
	
	vector<int> c(n * n);
	while(k --)
	{
		int u, v, w; cin >>u >>v >>w;
		u --, v --;
		c[u * n + v] = w;
	}

	for(int s = 1; s < (1 << n); s ++)
		for(int u = 0; u < n; u ++)
		{
			if(!(s >> u & 1)) continue;
			for(int v = 0; v < n; v ++)
			{
				if(s >> v & 1) continue;
				int ns = s | (1 << v);
				f[v][ns] = max(f[v][ns], f[u][s] + a[v] + c[u * n + v]);
			}
		}
	i64 ans = 0;
	for(int s = 0; s < (1 << n); s ++)
		for(int u = 0; u < n; u ++)
			if(__builtin_popcount(s) == m)
				ans = max(ans, f[u][s]);
	cout <<ans <<endl;
	return 0;
}
