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

vector<int> Z(string &s)
{
	int n = s.size();
	vector<int> z(n);
	z[0] = n;
	for(int i = 1, l = 0, r = 0; i < n; i ++)
	{
		if(i <= r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i] ++;
		if(i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b; cin >>a >>b;

	auto z = Z(b);
	i64 ans1 = 0;
	for(int i = 0; i < b.size(); i ++)
		ans1 ^= 1LL * (i + 1) * (z[i] + 1);
	
	i64 ans2 = 0;
	int p0 = 0;
	while(p0 < a.size() && p0 < b.size() && a[p0] == b[p0]) p0 ++;
	ans2 ^= 1LL * 1 * (p0 + 1);

	for(int i = 1, l = 0, r = p0 - 1; i < a.size(); i ++)
	{
		int p = 0;
		if(i <= r) p = min(r - i + 1, z[i - l]);

		while(i + p < a.size() && p < b.size() && a[i + p] == b[p]) p ++;

		if(i + p - 1 > r)
		{
			l = i;
			r = i + p - 1;
		}
		ans2 ^= 1LL * (i + 1) * (p + 1);
	}
	cout <<ans1 <<endl <<ans2 <<endl;
	return 0;
}
