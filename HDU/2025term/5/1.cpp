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

void tell(int l, int r, vector<int> &v)
{
	for(int i = l; i <= r; i ++)
		cout <<v[i] <<" \n"[i == r];
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
		vector f(m + 1, vector<int>(v + 1));
		f[0][0] = 1;
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			for(int j = 1; j <= m; j ++)
				for(int k = x; k <= v; k ++)
					f[j][k] = (f[j][k] + f[j - 1][k - x]) % mod;
		}
		ll ans = 0;
		for(int k = 1; k <= v; k ++)
			ans = (ans + f[m][k]) % mod;
		cout <<ans <<endl;
	}
	return 0;
}