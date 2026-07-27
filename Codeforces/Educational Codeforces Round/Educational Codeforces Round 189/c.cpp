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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector g(3, vector<char>(n + 1));
		for(int i = 1; i <= 2; i ++)
			for(int j = 1; j <= n; j ++)
				cin >>g[i][j];

		// auto calc = [&](int a, int b) -> int
		// {
		// 	int c1 = 0, c2 = 0;
		// 	for(int i = 1; i <= 2; i ++)
		// 		for(int j = a; j <= b; j ++)
		// 			c1 += (g[i][j] == 'R'), c2 += (g[i][j] == 'B');
		// 	return 4 - max(c1, c2);
		// };

		vector<int> f(n + 1, INF);
		f[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			//竖着
			f[i] = min(f[i - 1], f[i - 1]) + (g[1][i] != g[2][i]);

			//横着
			if(i - 2 >= 0) f[i] = min(f[i], f[i - 2] + (g[1][i] != g[1][i - 1]) + (g[2][i] != g[2][i - 1]));
		}
		cout <<f[n] <<endl;
	}
	return 0;
}
