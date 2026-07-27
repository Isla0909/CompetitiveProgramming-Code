#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	string s; cin >>s;
	s = ' ' + s;

	vector<i64> f(m + 1);
	f[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == 'A')
		{
			for(int j = m; j >= 1; j --)
				f[j] = (f[j] + 2 * f[j - 1]) % mod;
		}
		else if(s[i] == 'B')
		{
			for(int j = m; j >= 1; j --)
				f[j] = (f[j] + f[j - 1]) % mod;
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= m; i ++)
	{
		ans += f[i];
		ans %= mod;
	}
	cout <<ans % mod <<endl;
	return 0;
}