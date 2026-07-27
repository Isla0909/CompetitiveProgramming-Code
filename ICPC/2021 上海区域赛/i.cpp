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

i64 f[101][101][5201];//f[i][j][k]表示前i个数使用了j次翻转点数差为k - 2600的最大价值和

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector<pii> v(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>v[i].ff >>v[i].se;

	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= k; j ++)
			for(int u = 0; u <= 5200; u ++)
				f[i][j][u] = -inf;

	f[0][0][2600] = 0;
	//cout <<f[0][1][2601] <<endl;
	for(int i = 1; i <= n; i ++)
	{
		auto [w, t] = v[i];
		for(int j = 0; j <= k; j ++)
		{
			for(int u = 0; u <= 5200; u ++)
			{
				//不选
				f[i][j][u] = max(f[i][j][u], f[i - 1][j][u]); 

				//不翻倍
				f[i][j][u] = max(f[i][j][u], f[i - 1][j][u - t] + w); //给1
				f[i][j][u] = max(f[i][j][u], f[i - 1][j][u + t] + w); //给2

				if(j == 0) continue;

				//翻倍
				f[i][j][u] = max(f[i][j][u], f[i - 1][j - 1][u - 2 * t] + w);
				f[i][j][u] = max(f[i][j][u], f[i - 1][j - 1][u + 2 * t] + w);
			}
			//cout <<i <<" " <<j <<" " <<f[0][1][2601] <<" " <<f[1][1][2601] <<endl;
		}
	}
	//cout <<f[1][0][2601] <<" " <<f[1][1][2601] <<endl;
	i64 ans = 0;
	for(int j = 0; j <= k; j ++)
		ans = max(ans, f[n][j][2600]);
	cout <<ans <<endl;
	return 0;
}