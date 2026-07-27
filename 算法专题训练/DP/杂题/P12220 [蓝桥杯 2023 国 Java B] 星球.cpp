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

struct point
{
	int x, y, z;
	int w;
}p[20];

double dis(int i, int j)
{
	int dx = p[i].x - p[j].x, dy = p[i].y - p[j].y, dz = p[i].z - p[j].z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 0; i < n; i ++)
		cin >>p[i].x >>p[i].y >>p[i].z >>p[i].w;
	vector d(n, vector<double>(n));
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			d[i][j] = d[j][i] = dis(i, j);

	vector f(1 << n, vector<double>(n, inf));
	for(int i = 0; i < n; i ++) 
		f[0][i] = 0;
	for(int i = 0; i < 1 << n; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(i >> j & 1)
			{
				for(int k = 0; k < n; k ++)
					if(i >> k & 1) f[i][j] = min(f[i][j], f[i - (1 << j)][k] + 1.0 * d[k][j] * p[j].w);
			}
		}
	double ans = inf;
	for(int i = 0; i < n; i ++)
		ans = min(ans, f[(1 << n) - 1][i]);
	cout <<fixed <<setprecision(2) <<ans <<endl;
	return 0;
}