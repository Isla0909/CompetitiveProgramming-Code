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

double dis(int a, int b, int c, int d)
{
	int dx = a - c, dy = b - d;
	return sqrt(dx * dx + dy * dy);
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int d, r, x, y; cin >>d >>r >>x >>y;
		if(x >= 0 && y <= d && y >= -d) cout <<abs(x - r) <<endl;
		else if(x < 0 && y <= d && y >= -d) cout <<abs(x + r) <<endl;
		else if(y > d)
		{
			double c = dis(x, y, 0, d);
			cout <<fixed <<setprecision(0) <<abs(c - r) <<endl;
		}
		else if(y < d)
		{
			double c = dis(x, y, 0, -d);
			cout <<fixed <<setprecision(0) <<abs(c - r) <<endl;
		}
	}
	return 0;
}