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
using u32 = unsigned;
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
		int n, m, v; cin >>n >>m >>v;
		int a[n + 1], s[n + 1]; s[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			s[i] = s[i - 1] + a[i];
		}
		vector<int> f(m + 1), g(m + 1);
		int j = 0; f[0] = 0;
		for(int i = 1; i <= m; i ++)
		{
			while(j <= n && s[j] - s[f[i - 1]] < v)
				j ++;
			f[i] = j;
		}
		j = n, g[0] = n;
		for(int i = 1; i <= m; i ++)
		{
			while(j >= 0 && s[g[i - 1]] - s[j] < v)
				j --;
			g[i] = j;
		}
		int ans = -1;
		tell(f), tell(g);
		for(int i = 0; i <= m; i ++)
		{
			//cout <<"l and r" <<f[i] <<" " <<g[m - i] <<endl;
			if(f[i] <= g[m - i])
				ans = max(ans, s[g[m - i]] - s[f[i]]);
		}
		cout <<ans <<endl;
	}
	return 0;
}