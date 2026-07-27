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

constexpr int N = 100 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int a[N][N], b[N][N];
int cost[N * N], w[N * N], cnt[N * N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, t, v; cin >>n >>m >>t >>v;
	v = min(v - 1, t);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>a[i][j];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >>b[i][j];

	int idx = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(a[i][j] && b[i][j])
			{
				cost[idx] = (i + j) * 2;
				w[idx] = a[i][j];
				cnt[idx] = b[i][j];
				idx ++;
			}
		}
	vector<int> f(N * N);
	for(int i = 1; i <= idx; i ++)
	{
		for(int j = 1; j <= cnt[i]; j ++)
			for(int k = v; k >= cost[i]; k --)
				f[k] = max(f[k], f[k - cost[i]] + w[i]);
	}
	cout <<f[v] <<endl;
	return 0;
}