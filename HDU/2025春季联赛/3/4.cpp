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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector <pii> c(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>c[i].ff;
			c[i].se = i;
		}

		sort(c.begin() + 1, c.end());

		vector <bool> st(n + 1, 0);
		for(int i = 0; i < m; i ++)
		{
			int x; cin >>x;
			st[x] = 1;
		}
		vector f(n + 1, vector<int>(2, inf));
		
		auto calc = [&](int x) -> int 
		{
			return x * x;
		};

		f[1][0] = 0;
		if(!st[c[1].se]) f[2][0] = 0;

		f[2][1] = calc(c[2].ff - c[1].ff);

		for(int i = 3; i <= n; i ++)
		{
			f[i][1] = f[i - 1][0] + calc(c[i].ff - c[i - 1].ff);
			if(!st[c[i - 1].se])
			{
				f[i][0] = min(f[i - 1][0], f[i - 1][1]);
				f[i][1] = min(f[i][1], f[i - 2][0] + calc(c[i].ff - c[i - 2].ff));
			}
			else f[i][0] = f[i - 1][1];
		}
		int ans = f[n][1];
		if(!st[c[n].se]) ans = min(ans ,f[n][0]);
		cout <<ans <<endl;
	}
	return 0;
}