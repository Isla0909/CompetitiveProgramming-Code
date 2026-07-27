#pragma GCC optimize ("O2")
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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

bool check(int p, int c, i64 x)
{
	i128 res = 1;
	while(c --)
	{
		res *= p;
		if(res > x) return true; 
	}
	return res > x;
}

int isqrt(i64 x)
{
	int l = -1, r = 1e9 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(1LL * mid * mid > x) r = mid;
		else l = mid;
	}
	return l;
}

i64 read()
{
    i64 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        f *= (ch == '-' ? -1 : 1), ch = getchar();
    while (ch >= 48 && ch <= 57)
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}

void write(i64 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar((x % 10) ^ 48);
}

signed main()
{
	i64 lim = 1e18;
	vector<i64> v;
	for(int i = 2; (i128)i * i * i <= lim; i ++)
	{
		i128 cur = (i128)i * i * i;
		while(cur <= lim)
		{
			v.emplace_back(cur);
			cur *= i;
		}
	}
	//cout <<v.size() <<endl;
	sort(v.begin(), v.end());

	int q = read();
	while(q --)
	{
		i64 x = read();
		
		i64 ans = isqrt(x) - 1;
		ans += upper_bound(v.begin(), v.end(), x) - v.begin();
		write(ans);
		putchar('\n');
	}

	return 0;
}
