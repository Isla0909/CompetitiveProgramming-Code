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

constexpr int N = 1e6 + 1, INF = 0x3f3f3f3f, mod = 1e9 + 7;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), f(n + 1, -1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		auto dfs = [&](this auto &&self, int x) -> i32
		{
			if(x == n + 1) return 0;

			auto &v = f[x];
			if(v != -1) return v;

			int nex = x + a[x];
			if(nex > n)
			{
				v = min(n - x + 1, self(x + 1) + 1);
				return v;
			}
			v = min(self(nex + 1), self(x + 1) + 1);
			return v;
		};
		cout <<dfs(1) <<endl;
	}
	return 0;
}