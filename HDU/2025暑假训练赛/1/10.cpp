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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> p(n + 1);
		for(int i = 1; i <= n; i ++) cin >>p[i];

		i64 sum = 0;
		for(int k = 1; k <= n; k ++)
		{
			int x = p[k];
			vector<int> l(2 * n + 1), r(2 * n + 1);
			l[n] = r[n] = k;

			int s = 0;
			for(int i = k - 1; i >= 1; i --)
			{
				s += (p[i] > x ? 1 : -1);

				int idx = s + n;
				l[idx] += i;
			}

			s = 0;
			for(int i = k + 1; i <= n; i ++)
			{
				s += (p[i] > x ? 1 : -1);

				int idx = s + n;
				r[idx] += i;
			}

			for(int i = 0; i <= 2 * n; i ++)
			{
				int j = 2 * n - i;
				sum += 1LL * l[i] * r[j] * x;
			}
		}
		cout <<sum <<endl;
	}
	return 0;
}