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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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
	vector<vector<int>> w(n + 1, vector<int>(4));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= 3; j ++)
			cin >>w[i][j];

	int ans = 0;
	for(int u = 1; u <= 3; u ++)
	{
		vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(4, vector<int>(2, 0)));
		f[1][u][0] = f[1][u][1] = w[1][u];
		for(int i = 2; i <= n; i ++)
		{
			f[i][1][0] = max(f[i - 1][2][1], f[i - 1][3][1]) + w[i][1];
			f[i][2][0] = f[i - 1][3][1] + w[i][2];
			f[i][2][1] = f[i - 1][1][0] + w[i][2];
			f[i][3][1] = max(f[i - 1][1][0], f[i - 1][2][0]) + w[i][3];
		}
		for(int i = 1; i < u; i ++) ans = max(ans, f[n][i][0]);
		for(int i = u + 1; i <= 3; i ++) ans = max(ans, f[n][i][1]);
	}
	cout <<ans <<endl;
	return 0;
}