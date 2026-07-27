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

struct cxy
{
	int a, b, c, d;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	unordered_map<i64, unordered_map<i64, int>> mp;

	int n; cin >>n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i ++)
		cin >>x[i] >>y[i];

	auto dis = [&](int i, int j) -> i64
	{
		int dx = x[i] - x[j], dy = y[i] - y[j];
		return 1LL * dx * dx + 1LL * dy * dy;
	};

	unordered_map<i64, int> cnt;

	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
		{
			int dx = x[i] - x[j], dy = y[i] - y[j];
			i64 d = dis(i, j);

			int gcd = __gcd(abs(dy), abs(dx));
			dy /= gcd, dx /= gcd;

			// 统一符号：dx为正；若dx=0，则dy为正
			if (dx < 0) 
			{
			    dy = -dy;
			    dx = -dx;
			} 
			else if (dx == 0) dy = 1;

			// 计算哈希（此时dy和dx的符号已统一）
			i64 hash = 20000000LL * dy + dx;
			mp[hash][d] ++, cnt[hash] ++;
		}

	i64 ans = 0;
	for(auto [_, c] : cnt)
	{
		if(c < 2) continue;
		i64 d = 1LL * c * (c - 1) / 2;
		ans += d;
	}
	
	i64 h = 0;
	for(auto [k, m] : mp)
	{
		for(auto [d, c] : m)
		{
			if(c < 2) continue;
			i64 add = 1LL * c * (c - 1) / 2;
			h += add;
		}
	}
	cout <<ans - h / 2 <<endl;
	return 0;
}