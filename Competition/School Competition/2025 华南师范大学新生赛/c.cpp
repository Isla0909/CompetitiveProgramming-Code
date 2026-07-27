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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

double random(double l, double r)
{
	return 1.0 * rng() / rng.max() * (r - l) + l;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int start = clock();

	int n, m; cin >>n >>m;
	vector g(n + 1, vector<array<int, 3>>(m + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			string s; cin >>s;
			g[i][j][0] = stoi(s.substr(0, 3)), g[i][j][1] = stoi(s.substr(4, 3)), g[i][j][2] = stoi(s.substr(8, 3));
		}

	i64 ans = inf;
	auto calc = [&](array<int, 3> &c)
	{
		i64 res = 0;
		auto [x1, y1, z1] = c;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				auto [x2, y2, z2] = g[i][j];
				int dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
				res += dx * dx + dy * dy + dz * dz;
			}
		ans = min(ans, res);
		return res;
	};

	auto simulate_anneal = [&]() -> void
	{
		array<int, 3> cur = {rand(0, 255), rand(0, 255), rand(0, 255)};
		auto &[x, y, z] = cur;
		for(double t = 128; t >= 1; t *= 0.93)
		{
			int c = t;
			auto &[x, y, z] = cur;
			array<int, 3> np = {rand(x - c, x + c), rand(y - c, y + c), rand(z - c, z + c)};
			i64 delta = calc(np) - calc(cur);
			if(exp(-delta / t) > random(0, 1))
			{
				x = np[0], y = np[1], z = np[2];
			}
		}
	};

	for(int T = 0; T < 300; T ++)
	{
		if(1000 * (clock() - start)>= 900 * CLOCKS_PER_SEC) break;
		simulate_anneal();
	}
	cout <<ans <<endl;
	return 0;
}
