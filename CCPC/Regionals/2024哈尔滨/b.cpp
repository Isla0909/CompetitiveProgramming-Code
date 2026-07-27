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
typedef pair<bool, i64> pbi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<pbi> f(n + 1); f[0] = {false, 0};
	for(int i = 1; i <= n; i ++)
	{
		f[i].ff |= f[i - 1].ff | (f[i - 1].se % 2);

		if(f[i - 1].se >= 0) f[i].se = a[i] + f[i - 1].se / 2;
		else
		{
			int r = f[i - 1].se % 2;
			if(!r) f[i].se = a[i] + f[i - 1].se / 2;
			else f[i].se = a[i] + f[i - 1].se / 2 - 1;
		}

		if(!f[i].ff && !f[i].se) cout <<'0';
		else if(f[i].se < 0) cout <<'-';
		else cout <<'+';
	}
	cout <<endl;
	return 0;
}