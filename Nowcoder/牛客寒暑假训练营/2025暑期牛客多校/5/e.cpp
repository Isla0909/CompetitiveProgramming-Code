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
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector cnt(27, vector<vector<int>>(2, vector<int>(2)));
	for(int i = 0; i < n; i ++)
	{
		int a; cin >>a;

		int x = 0;
		for(int j = 0; j < 27; j ++)
		{
			x += (a >> j & 1);
			cnt[j][a >> j & 1][x % 2] ++;
		}
	}

	i64 ans = 0;
	for(int i = 0; i < 27; i ++)
		ans += 1LL * (1 << i) * (1LL * cnt[i][0][0] * cnt[i][1][1] + 1LL * cnt[i][0][1] * cnt[i][1][0]);
	cout <<ans <<endl;

	return 0;
}