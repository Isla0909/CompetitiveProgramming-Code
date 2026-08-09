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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

i64 get(i64 x, i64 p)
{
	if(p == 1) return x;
	i64 res = 0;
	while(x)
	{
		i64 c = x % p;
		res += c;
		x /= p;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; i64 p; cin >>n >>p;
	i64 c1 = 0, c2 = 0;
	for(int i = 0; i < n; i ++)
	{
		i64 x; cin >>x;
		c1 += get(x, p), c2 += get(x, p);
		c1 %= 2; c2 %= p;
	}
	if(c1 & 1) cout <<"GOOD" <<endl;
	else cout <<"BAD" <<endl;
	return 0;
}