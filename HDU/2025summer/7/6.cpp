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

	int T; cin >>T;
	while(T --)
	{
		int k, n, a, b, c, d; cin >>k >>n >>a >>b >>c >>d;
		int l = ceil(1.0 * k * d / (1.0 * c * n)), r = k * b / (a * n);

		i64 deno1 = d, nume1 = ((k * d) / (n * c) + 1) * c;
		i64 gcd = __gcd(deno1, nume1);
		deno1 /= gcd, nume1 /= gcd;

		i64 deno2 = n * l, nume2 = k * (l + 1);
		gcd = __gcd(deno2, nume2);
		deno2 /= gcd, nume2 /= gcd;

		if(l > r) cout <<nume1 <<'/' <<deno1 <<endl;
		else if(nume1 * deno2 >= nume2 * deno1) cout <<nume1 <<'/' <<deno1 <<endl;
		else cout <<nume2 <<'/' <<deno2 <<endl;
	}
	return 0;
}