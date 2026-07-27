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
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 100 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	char s[N][N], t[N][N];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >>s[i][j];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >>t[i][j];
	auto calc = [&]() -> int
	{
		int res = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				res += (s[i][j] != t[i][j]);
		return res;
	};

	auto transform = [&]() -> void
	{
		char g[N][N];
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				g[i][j] = s[n + 1 - j][i];
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				s[i][j] = g[i][j];
	};

	int ans = INF;
	ans = min(ans, calc());
	for(int i = 0; i < 3; i ++)
	{
		transform();
		ans = min(ans, calc() + i + 1);
	}
	cout <<ans <<endl;
	return 0;
}