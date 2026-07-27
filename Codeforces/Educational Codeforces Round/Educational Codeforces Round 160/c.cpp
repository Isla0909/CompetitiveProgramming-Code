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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int m; cin >>m;
	vector<int> cnt(31);
	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int x; cin >>x;
			cnt[x] ++;
		}
		else
		{
			int x; cin >>x;
			for(int i = 29; i >= 0; i --)
			{
				int c = min(cnt[i], x >> i);
				x -= c << i;
			}
			cout <<(x ? "NO" : "YES") <<endl;
		}
	}

	return 0;
}