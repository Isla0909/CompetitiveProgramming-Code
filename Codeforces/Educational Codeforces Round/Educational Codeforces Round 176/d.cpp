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

vector f(63, vector(63, vector<ll>(30, inf)));
vector g(63, vector<ll>(63, inf));

void initial()
{
	for(int i = 0; i < f.size(); i ++)
		for(int j = 0; j < f[0].size(); j ++)
			for(int k = 0; k < f[0][0].size(); k ++)
			{
				if(i + j == 0) f[i][j][k] = 0;
				else if(k)
				{
					//不选k
					f[i][j][k] = min(f[i][j][k], f[i][j][k - 1]);
					//选k
					//f[i][j][k] = min(f[i][j][k], min(f[i - k][j][k - 1], f[i][j - k][k - 1]) + (ll)(1 << k));
					//记得边界判断
					if(i >= k) f[i][j][k] = min(f[i][j][k], f[i - k][j][k - 1] + (ll)(1 << k));
					if(j >= k) f[i][j][k] = min(f[i][j][k], f[i][j - k][k - 1] + (ll)(1 << k));
				}
			}
	for(int i = 0; i < g.size(); i ++)
		for(int j = 0; j < g[0].size(); j ++)
			for(int k = 0; k < f[0][0].size(); k ++)
				g[i][j] = min(g[i][j], f[i][j][k]);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	initial();

	int T; cin >>T;
	while(T --)
	{
		ll x, y; cin >>x >>y;
		if(x == y)
		{
			cout <<0 <<endl;
			continue;
		}
		vector <int> a, b;
		while(x)
		{
			int t = (x & 1) ? 1 : 0;
			a.push_back(t);
			x >>= 1;
		}
		while(y)
		{
			int t = (y & 1) ? 1 : 0;
			b.push_back(t);
			y >>= 1;
		}
		reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
		int len = 0;
		for(int i = 0; i < a.size() && i < b.size(); i ++)
			if(a[i] == b[i]) len = i + 1;
			else break;
		int l1 = a.size() - len, l2 = b.size() - len;
		ll ans = inf;
		for(int i = 0; i < len; i ++)
			ans = min(ans, g[l1 + i][l2 + i]);
		for(int i = a.size(); i < 63; i ++)
			for(int j = b.size(); j < 63; j ++)
				ans = min(ans, g[i][j]);
		cout <<ans <<endl;
	}
	return 0;
}