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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
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

	int n; cin >>n;
	string s, t; cin >>s >>t;

	ll ans = 0; int k = 0;
	for(int i = 0; i < n; i ++)
	{
		int a = s[i] - 'a', b = t[i] - 'a';
		if((b + k) % 26 == a) continue;

		int x = (a + 26) - (b + k) % 26;
		ans ++;
		k += x, k %= 26;
	}
	cout <<ans <<endl;
	return 0;
}