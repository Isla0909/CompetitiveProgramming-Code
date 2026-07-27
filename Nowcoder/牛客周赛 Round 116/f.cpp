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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

	int n, m; cin >>n >>m;
	vector<pair<int, u64>> a;
	vector<bool> st(200010);
	vector<u64> s(200010, 0);
	for(int i = 0; i < n; i ++)
	{
		int l, r; cin >>l >>r;
		st[l] = st[r] = 1;

		u64 x = rng();
		s[l] ^= x;
		s[r] ^= x;
	}

	sort(a.begin(), a.end());

	unordered_map<u64, int> mp;
	u64 cur = 0;
	for(int i = 1; i <= m; i ++)
	{
		if(st[i]) cur ^= s[i];
		else mp[cur] ++; 
	}

	i64 ans = 0;
	for(auto [x, c] : mp)
	{
		ans += c;
		if(c >= 2) ans += 1LL * c * (c - 1) / 2;
	}
	cout <<ans <<endl;
	return 0;
}