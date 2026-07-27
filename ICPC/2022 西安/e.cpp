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

i64 p[40];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < 40; i ++)
		p[i] = p[i - 1] * 3LL;

	int T; cin >>T;
	while(T --)
	{
		i64 l, r; cin >>l >>r;
		vector<int> L(40), R(40);
		for(int i = 39; i >= 0; i --)
		{
			L[i] = l / p[i] % 3;
			R[i] = r / p[i] % 3;
		}

		bool f = 0; i64 pre = 0;
		int ans = 0, sum = 0;
		for(int i = 39; i >= 0; i --)
		{
			if(R[i]) f = 1;
			if(!f) continue;

			if(R[i] && pre + (R[i] - 1) * p[i] + (p[i] - 1) >= l)
			{
				if(R[i] > 1 || sum) ans = max(ans, sum + R[i] - 1 + 1 + 2 * i + i);
				else ans = max(ans, 3 * i);
			}
			pre += R[i] * p[i];
			sum += R[i] + 1;
		}
		ans = max(ans, sum);
		cout <<ans <<endl;
	}
	return 0;
}
