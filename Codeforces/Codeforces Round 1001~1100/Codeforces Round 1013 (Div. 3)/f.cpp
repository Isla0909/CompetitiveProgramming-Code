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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, d; cin >>n >>m >>d;
		vector g(n, vector<char>(m));
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				cin >>g[i][j];

		vector<int> f(m, 0), h(m, 0), pref(m + 1, 0), preh(m + 1, 0);
		for(int i = 0; i < n; i ++)
		{
			//上下扩展
			for(int j = 0; j < m; j ++)
			{
				if(!i && g[i][j] == 'X') f[j] = 1;
				else if(g[i][j] == 'X')
				{
					int l = max(1LL, j + 1 - (d - 1)), r = min(m , j + 1 + (d - 1));
					f[j] = pref[r] - pref[l - 1] + preh[r] - preh[l - 1] + mod + mod;
					f[j] %= mod;
				}
				else f[j] = 0;
			}
			for(int j = 0; j < m; j ++)
				pref[j + 1] = pref[j] + f[j], pref[j + 1] %= mod;
			//同层扩展
			for(int j = 0; j < m; j ++)
			{
				if(g[i][j] == 'X')
				{
					int l = max(1LL, j + 1 - d), r = min(m, j + 1 + d);
					h[j] = pref[r] - pref[l - 1] - f[j] + mod + mod;
					h[j] %= mod;
				}
				else h[j] = 0;
			}
			for(int j = 0; j < m; j ++)
				preh[j + 1] = preh[j] + h[j], preh[j + 1] %= mod;
		}
		cout <<(pref[m] + preh[m]) % mod <<endl;
	}
	return 0;
}