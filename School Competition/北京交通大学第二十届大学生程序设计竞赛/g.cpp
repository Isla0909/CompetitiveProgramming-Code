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

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

bool check(vector<vector<int>> &g)
{
	for(int i = 1; i < g.size(); i ++)
		for(int j = 1; j < g[i].size(); j ++)
			if(i + 1 < g.size() && g[i][j] == g[i + 1][j] || j + 1 < g[i].size() && g[i][j] == g[i][j + 1]) return false;
	return true;
}

void display(vector<vector<int>> &g)
{
	for(int i = 1; i < g.size(); i ++)
		tell(1, g[i]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];

		auto g1 = g, g2 = g;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= n; i ++)
		{
			int s = 1 + (i & 1);
			for(int j = s; j <= m; j += 2)
			{
				while(i - 1 >= 1 && g1[i][j] == g1[i - 1][j] || j - 1 >= 1 && g1[i][j] == g1[i][j - 1])
					g1[i][j] ++, cnt1 ++;
			}
		}

		for(int i = 1; i <= n; i ++)
		{
			int s = 2 - (i & 1);
			for(int j = s; j <= m; j += 2)
			{
				while(i - 1 >= 1 && g2[i][j] == g2[i - 1][j] || j - 1 >= 1 && g2[i][j] == g2[i][j - 1])
					g2[i][j] ++, cnt2 ++;
			}
		}

		cout <<"YES" <<endl;
		if(check(g1) && cnt1 <= n * m / 2) display(g1);
		else
		{
			if(!check(g2))
			{
				for(int i = 1; i <= n; i ++)
					for(int j = 1; j <= m; j ++)
					{
						while(i - 1 >= 1 && g2[i][j] == g2[i - 1][j] || j - 1 >= 1 && g2[i][j] == g2[i][j - 1])
							g2[i][j] ++, cnt2 ++;
					}
				assert(check(g2));
			}
			display(g2);
		}
	}

	return 0;
}
