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
// 
// [l1, r1], [l2, r2] ....... 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, m; cin >>n >>m;
	string s; cin >>s;
	s = " " + s; int ans = INF;
	for(char i = 'a'; i <= 'z'; i ++)
	{
		vector<pii> v;
		for(int u = 1; u <= n; u ++)
		{
			if(s[u] == i) continue;
			int j = u;
			while(j + 1 <= n && s[j + 1] != i) j ++;
			v.emplace_back(u, j);
			u = j;
		}

		int res = 0, now = 0;
		for(int u = 0; u < v.size(); u ++)
		{
			auto [l, r] = v[u];
			if(now <= l) now = l;

			if(now <= r)
			{
				int k = (r + 1 - now + m - 1) / m;
				now += k * m;
				res += k;
			}
		}
		ans = min(ans, res);
	}
	cout <<ans <<endl;
	return 0;
}
