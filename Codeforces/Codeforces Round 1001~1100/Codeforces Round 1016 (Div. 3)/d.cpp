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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int find(int n, int x, int y)
{

	//cout <<x <<" " <<y <<endl;

	if(n == 1)
	{
		if(x == 1 && y == 1) return 1;
		if(x == 2 && y == 2) return 2;
		if(x == 2 && y == 1) return 3;
		return 4;
	}

	int len = pow(2, n - 1), s = len * len;
	if(x <= len && y <= len) return find(n - 1, x, y);
	if(x > len && y > len) return s + find(n - 1, x - len, y - len);
	if(x > len && y <= len) return 2 * s + find(n - 1, x - len, y);
	return 3 * s + find(n - 1, x, y - len);
}

pii calc(int n, int d)
{
	if(n == 1)
	{
		if(d == 1) return {1, 1};
		if(d == 2) return {2, 2};
		if(d == 3) return {2, 1};
		return {1, 2};
	}
	int len = pow(2, n - 1), s = len * len;
	if(d <= s) return calc(n - 1, d);
	else if(d <= s * 2)
	{
		auto [a, b] = calc(n - 1, d - s);
		return {a + len, b + len};;
	}
	else if(d <= 3 * s)
	{
		auto [a, b] = calc(n - 1, d - s * 2);
		return {a + len, b};
	}
	else
	{
		auto [a, b] = calc(n - 1, d - s * 3);
		return {a, b + len};
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;

		while(m --)
		{
			string s; cin >>s;
			if(s == "->")
			{
				int x, y; cin >>x >>y;
				cout <<find(n, x, y) <<endl;
			}
			else
			{
				int d; cin >>d;
				auto t = calc(n, d);
				cout <<t.ff <<" " <<t.se <<endl;
			}
		}
	}
	return 0;
}