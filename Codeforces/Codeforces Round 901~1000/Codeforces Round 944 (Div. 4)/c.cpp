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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int a, b, c, d; cin >>a >>b >>c >>d;
		a %= 12, b %= 12, c %= 12, d %= 12;

		if(a > b) swap(a, b);

		int f1, f2;
		if(c > a && c < b) f1 = 1;
		else if(c == a || c == b) f1 = 0;
		else f1 = -1;

		if(d > a && d < b) f2 = 1;
		else if(d == a || d == b) f2 = 0;
		else f2 = -1;

		if(f1 * f2 == 1) cout <<"NO" <<endl;
		else cout <<"YES" <<endl;
	}
	return 0;
}