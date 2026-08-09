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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<int>(m + 1));
	vector<vector<int>> x(n * m + 1, {0}), y(n * m + 1, {0});
	unordered_map<int, int> mp; int id = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			int c; cin >>c;
			g[i][j] = c;
			if(!mp.count(c)) mp[c] = id ++;
			c = mp[c];
			x[c].push_back(i);
			y[c].push_back(j);
		}
	for(int i = 1; i <= n * m; i ++)
	{
		if(x[i].size() > 2)
		{
			sort(x[i].begin() + 1, x[i].end());
			sort(y[i].begin() + 1, y[i].end());
		}
	}

	i64 ans = 0;
	for(int i = 1; i <= n * m; i ++)
	{
		if(x[i].size() <= 2) continue;
		int l = x[i].size() - 1;
		vector<i64> pre(l + 1);
		for(int j = 1; j <= l; j ++)
			pre[j] = pre[j - 1] + x[i][j];

		for(int j = 1; j <= l; j ++)
		{
			int cnt = l - j;
			ans += (pre[l] - pre[j]) - cnt * x[i][j];
		}
		for(int j = 1; j <= l; j ++)
			pre[j] = pre[j - 1] + y[i][j];
		for(int j = 1; j <= l; j ++)
		{
			int cnt = l - j;
			ans += (pre[l] - pre[j]) - cnt * y[i][j];
		}
	}
	cout <<ans * 2 <<endl;
	return 0;
}