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
#define int long long
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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int l, r; cin >>l >>r;

		auto calc = [&](int x) -> int
		{
			return r / x - (l - 1) / x;
		};

		int ans = (r - l + 1) - calc(2) - calc(3) - calc(5) - calc(7);
		ans += calc(6) + calc(10) + calc(14) + calc(15) + calc(21) + calc(35);
		ans -= calc(105) + calc(70) + calc(42) + calc(30);
		ans += calc(210);
		cout <<ans <<endl;
	}
	return 0;
}
