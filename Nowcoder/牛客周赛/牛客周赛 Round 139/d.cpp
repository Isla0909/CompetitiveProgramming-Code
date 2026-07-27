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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int p[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int quick_pow(int a, i64 b, int p = mod)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res % p;
}

int inv(int x)
{
	return quick_pow(x, mod - 2, mod);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	for(int i = 1; i <= n; i ++) p[i] = i;

	while(m --)
	{
		int a, b; cin >>a >>b;
		int pa = find(a), pb = find(b);
		if(pa != pb) p[pa] = pb;
	}

	int c = 0;
	for(int i = 1; i <= n; i ++)
		c += (p[i] == i);
	cout <<quick_pow(26, c) <<endl;
	return 0;
}
