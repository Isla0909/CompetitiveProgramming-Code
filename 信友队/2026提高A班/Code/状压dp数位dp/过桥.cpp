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

	int v, n; cin >>v >>n;
	vector<int> t(n), w(n);
	for(int i = 0; i < n; i ++)
		cin >>t[i] >>w[i];
	vector<int> f(1 << n, INF);
	f[0] = 0;

	vector<int> st(1 << n), g(1 << n);
	for(int s = 0; s < (1 << n); s ++)
	{
		int sum = 0, M = -1;
		for(int j = 0; j < n; j ++)
			if(s >> j & 1)
			{
				sum += w[j];
				M = max(M, t[j]);
			}
		if(sum <= v) st[s] = 1, g[s] = M;
	}

	for(int s = 0; s < (1 << n); s ++)
	{
		int mask = ((1 << n) - 1) ^ s;
		for(int i = mask; i; i = (i - 1) & mask)
			if(st[i]) f[s | i] = min(f[s | i], f[s] + g[i]);
	}
	cout <<f[(1 << n) - 1];
	return 0;
}
