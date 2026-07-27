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

i64 quick_pow(u64 a, u64 b, i64 p)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> f(10);
	f[1] = {1};
	f[2] = {2, 4, 8, 6};
	f[3] = {3, 9, 7, 1};
	f[4] = {4, 6};
	f[5] = {5};
	f[6] = {6};
	f[7] = {4, 8, 6, 2};
	f[8] = {8, 4, 2, 6};
	f[9] = {9, 1};

	int T; cin >>T;
	while(T --)
	{
		i64 a, b; cin >>a >>b;
		int x = a % 10;
		if(a == b)
		{
			cout <<x <<endl;
			continue;
		}
		i64 cnt = min((i64)4, b - a);
		i64 p = a + cnt - 1, q = a + cnt; 
		while(p != a)
		{
			q = quick_pow(p, q, 10000000000);
			p --;
			cout <<p <<" " <<q <<endl;
		}
		cout <<p <<" " <<q <<endl;
		cout <<quick_pow(p, q, 10) <<endl; 
	}
	return 0;
}