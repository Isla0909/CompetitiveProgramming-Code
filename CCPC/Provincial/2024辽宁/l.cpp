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
#define int long long
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

int quick_pow(int a, ll b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a;

		a = 1LL * a * a;
		b >>= 1;
	}
	return res;
}

bool judge(int x)
{
	int cnt = 0;
	for(int p = 0; p <= 8; p ++)
		if(x % (4LL * quick_pow(100, p)) == 0 && x % quick_pow(100, p + 1)) cnt ++;
	return cnt == 1;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T; bool f = 1;
	while(T --)
	{
		ll k; cin >>k;
		k += 1533;

		vector<pii> v(23);
		v[1] = {0, 1}, v[2] = {1, 3};
		for(int i = 3; i <= 20; i ++)
		{
			if(i & 1) v[i].ff = 25 * v[i - 1].ff - 1, v[i].se = 25 * v[i - 1].se + 1;
			else v[i].ff = 4 * v[i - 1].ff + 1, v[i].se = 4 * v[i - 1].se - 1;
		}

		int ans = 0;
		while(k)
		{
			int l = 0, r = 21;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(k - v[mid].se >= 0) l = mid;
				else r = mid;
			}
			k -= v[l].se;
			cout <<v[l].se <<" " <<k <<endl;
			ans += v[l].ff + v[l].se;
		}
		if(judge(ans)) ans --;
		cout <<ans <<endl;
	}
	return 0;
}