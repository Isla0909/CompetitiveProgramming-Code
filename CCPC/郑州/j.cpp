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

 int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	string s, t; cin >>s; int ans = 0;
	for(int i = 0; i < 26; i ++)
	{
		t = s; int res = 0;
		for(int j = 0; t[j]; j ++)
		{
			int x = (t[j] - 'A' + i) % 26;
			res += holes_cnt[x];
		}
		ans = max(res, ans); 
	}
	cout <<ans <<endl;
	return 0;
}