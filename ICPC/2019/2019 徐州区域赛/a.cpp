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

i64 get(i64 n)
{
	if(n % 4 == 0) return n;
	if(n % 4 == 1) return 1;
	if(n % 4 == 2) return n + 1;
	return 0;
}

i64 get(i64 l, i64 r)
{
	return get(r) ^ get(l - 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		i64 l, r, s; cin >>l >>r >>s;
		i64 ans = -1;
		for(i64 i = l; i <= min(l + 4, r); i ++)
			for(i64 j = r; j >= max(i, r - 4); j --)
				if(get(i, j) <= s) ans = max(ans, j - i + 1);
		cout <<ans <<endl;
	}
	return 0;
}
