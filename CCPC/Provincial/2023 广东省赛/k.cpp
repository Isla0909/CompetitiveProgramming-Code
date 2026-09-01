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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		int tot = n * m;
		unordered_map<i64, bool> mp;
		queue<i64> q; i64 val = 0;
		for(int i = 0; i < k; i ++)
		{
			int x, y; cin >>x >>y;
			x --, y --;
			int c = x * m + y;
			val |= (1LL << c);
		}

		auto get= [&](i64 x, int c) -> bool
		{
			return x >> c & 1LL;
		};

		auto change = [&](i64 t, int a, int b, int c) -> void
		{
			if(get(t, a) && get(t, b) && !get(t, c))
			{
				i64 nt = t - (1LL << a) - (1LL << b) + (1LL << c);
				q.emplace(nt);
			}
		};

		int ans = k;
		q.emplace(val);
		while(q.size())
		{
			auto t = q.front(); q.pop();
			ans = min(ans, __builtin_popcountll(t));

			if(mp[t]) continue;
			mp[t] = true;

			for(int i = 0; i < n; i ++)
				for(int j = 0; j < m; j ++)
				{
					for(int u = 0; u < 4; u ++)
					{						
						int x1 = i + dx[u], y1 = j + dy[u];
						int x2 = x1 + dx[u], y2 = y1 + dy[u];
						if(x2 < 0 || x2 > n - 1 || y2 < 0 || y2 > m - 1) continue;
						change(t, i * m + j, x1 * m + y1, x2 * m + y2);
					}
				}
		}
		cout <<ans <<endl;
	}
	return 0;
}
