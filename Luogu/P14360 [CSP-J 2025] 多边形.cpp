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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	sort(a.begin() + 1, a.end());
	
	int m = 5000;
	vector<int> f(m + 1);
	f[0] = 1; 
	i64 pw = 1, ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int bad = 0;
		for(int s = 0; s <= a[i]; s ++)
			bad = (bad + f[s]) % mod;

		ans = (ans + pw - bad + mod) % mod;

		for(int s = m; s >= a[i]; s --)
			f[s] = (f[s] + f[s - a[i]]) % mod;
		pw = pw * 2 % mod;
	}
	cout <<ans <<endl;
	return 0;
}
