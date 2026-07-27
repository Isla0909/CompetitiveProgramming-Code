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
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int lowbit(int x)
{
	return x & -x;
}

bool is_perfect(int x)
{
	return x == lowbit(x);
}

int ceilLog(int x)
{
	return __lg(2 * x + 1);
}

int lev(int x)//求一个数的二进制有多少位
{
	return __lg(x);
}

int len(int x)
{
	return __lg(x) + 1;
}

int hbit(int x)
{
	return __lg(x);
}

int getbit(int x, int c)
{
	return (x >> c & 1);
}

int count1(int x)
{
	int res = 0;
	while(x)
	{
		x -= lowbit(x);
		res ++;
	}
	return res;
}

int count0(int x)
{
	return len(x) - count1(x);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		n %= m;
		int gcd = __gcd(n, m);
		if(!is_perfect(m / gcd))
		{
			cout <<-1 <<endl;
			continue;
		}
		cout <<1LL * count1(n / gcd) * m - n <<endl;
	}
	return 0;
}