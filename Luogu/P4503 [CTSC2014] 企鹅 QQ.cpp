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

	int n, L, S; cin >>n >>L >>S;
	vector<string> v;
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		s = " " + s;
		v.push_back(s);
	}

	vector h(n, vector<u64>(L + 1));
	u64 P = 131;
	vector<u64> p(L + 1); p[0] = 1;
	for(int i = 1; i <= L; i ++)
		p[i] = p[i - 1] * P;

	for(int i = 0; i < n; i ++)
	{
		for(int j = 1; j <= L; j ++)
			h[i][j] = h[i][j - 1] * P + (u64)v[i][j] + 1;
	}

	auto fun = [&](int i, int l, int r) -> u64
	{
		if(l > r) return 0ULL;
		return h[i][r] - h[i][l - 1] * p[r - l + 1];
	};

	int ans = 0;
	for(int i = 1; i <= L; i ++)
	{
		unordered_map<u64, int> mp;
		for(int j = 0; j < n; j ++)
		{
			int len = L - i;
			u64 val = fun(j, 1, i - 1) * p[len] + fun(j, i + 1, L);
			ans += mp[val];
			mp[val] ++;
		}
	}
	cout <<ans <<endl;
	return 0;
}
