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

constexpr int N = 3e3 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int g[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(g, 0x3f, sizeof g);

	int n, m, s, e; cin >>n >>m >>s >>e;
	for(int i = 0; i < m; i ++)
	{
		int a, b, c; cin >>a >>b >>c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	auto dijkstra = [&](int s) -> vector<i64>
	{
		vector<i64> dist(n + 1, inf);
		dist[s] = 0;
		vector<bool> st(n + 1);
		for(int i = 0; i < n; i ++)
		{
			int t = -1;
			for(int j = 1; j <= n; j ++)
			{
				if(!st[j] && (t == -1 || dist[j] < dist[t]))
					t = j;
			}
			st[t] = 1;
			for(int j = 1; j <= n; j ++)
				dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
		return dist;
	};
	auto dist = dijkstra(s);
	cout <<dist[e] <<endl;
	return 0;
}
