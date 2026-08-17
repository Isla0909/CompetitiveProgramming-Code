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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;

		s = " " + s;

		auto id = [&](char c) -> int
		{
			return c == '(';
		};

		vector<array<int, 2>> nex(n + 2);
		nex[n + 1] = {n + 1, n + 1};

		for(int i = n; i >= 1; i --)
		{
			nex[i] = nex[i + 1];
			nex[i][id(s[i])] = i;
		}

		vector<array<int, 2>> pre(n + 2);
		pre[0] = {0, 0};
		for(int i = 1; i <= n; i ++)
		{
			pre[i] = pre[i - 1];
			pre[i][id(s[i])] = i;
		}

		vector f(n + 2, vector<int>(n + 2));
		auto get = [&](int l, int r) -> int
		{
			return (l <= r) ? f[l][r] : 0;
		};

		for(int len = 1; len <= n; len ++)
			for(int l = 1; l + len - 1 <= n; l ++)
			{
				int r = l + len - 1;
				for(int x = 0; x < 2; x ++)
				{
					int y = x ^ 1;
					int a = nex[l][x];
					if(a > r) continue;

					int b = nex[a + 1][y];
					if(b > r) continue;

					int d = pre[r][x];
					if(d <= b) continue;

					int c = pre[d - 1][y];
					if(c <= b) continue;

					f[l][r] = max(f[l][r], 4 + get(b + 1, c - 1));
				}
			}

		int L = nex[1][1], R = pre[n][0];
		if(L < R) cout <<f[L + 1][R - 1] + 2 <<endl;
		else cout <<0 <<endl;
	}
	return 0;
}
