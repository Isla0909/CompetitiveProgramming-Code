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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

i64 rand(i64 l, i64 r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

i64 f(i64 x)
{
	i64 res = 1;
	while(x)
	{
		int t = x % 10;
		res *= t;
		x /= 10;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int cnt = 1000000;
	// int ans = 12; i64 shabi = -1;
	// while(1)
	// {
	// 	i64 x = rand(1, inf); int c = 0;
	// 	if(f(x) == f(789772172784848637)) continue;
	// 	i64 t = x;
	// 	while(x != f(x))
	// 	{
	// 		c ++;
	// 		x = f(x);
	// 	}
	// 	if(c == ans)
	// 	{
	// 		ans = c;
	// 		shabi = t;
	// 		break;
	// 	}
	// }
	// cout <<ans <<" " <<shabi <<endl;
	cout <<789772172784848637 <<" " <<79997999776999783 <<endl;
	return 0;
}
//12 789772172784848637