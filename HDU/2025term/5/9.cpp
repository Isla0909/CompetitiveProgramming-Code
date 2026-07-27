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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, ll b, int p)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res % p;
}

int inv(int x)
{
	return quick_pow(x, mod - 2, mod);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int x = n % 5, y = n / 5;

		if(x == 2 || x == 0) cout <<1 <<endl;
		else if(n == 1) cout <<inv(2) <<endl;
		else if(x == 3)
		{
			int t = quick_pow(2, y + 2, mod);
			cout <<(1 + mod - inv(t)) % mod <<endl;
		}
		else if(x == 4)
		{
			int t = quick_pow(2, y + 1, mod);
			cout <<(1 + mod - inv(t)) % mod <<endl;
		}
		else if(x == 1)
		{
			int t = quick_pow(2, y, mod);
			cout <<(1 + mod - inv(t)) % mod <<endl;
		}
	}
	return 0;
}