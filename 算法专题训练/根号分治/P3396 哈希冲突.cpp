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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	int len = sqrt(n);

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector f(len + 1, vector<int>(len));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= len; j ++)
			f[j][i % j] += a[i];

	while(m --)
	{
		char op; cin >>op;
		if(op == 'A')
		{
			int x, y; cin >>x >>y;
			if(x <= len) cout <<f[x][y] <<endl;
			else
			{
				int ans = 0;
				for(int i = y; i <= n; i += x)
					ans += a[i];
				cout <<ans <<endl;
			}
		}
		else
		{
			int p, x; cin >>p >>x;
			for(int i = 1; i <= len; i ++)
				f[i][p % i] += x - a[p];
			a[p] = x;
		}
	}
	return 0;
}