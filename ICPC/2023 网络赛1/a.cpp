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

struct cxy
{
	string s;
	int rk, c;
};

bool cmp(const cxy &a, const cxy &b)
{
	if(a.rk != b.rk) return a.rk < b.rk;
	return a.c < b.c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	map<string, pii> mp;
	int rk = 1;
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		if(!mp.count(s))
		{
			mp[s] = {rk, 1};
			rk ++;
		}
	}
	rk = 1;
	unordered_map<string, bool> st;
	for(int i = 0; i < m; i ++)
	{
		string s; cin >>s;
		if(!mp.count(s))
		{
			mp[s] = {rk, 2};
			rk ++;
		}
		else if(mp[s].ff > rk)
		{
			mp[s] = {rk, 2};
			if(!st.count(s)) st[s] = 1;
			rk ++;
		}
		else if(mp[s].se == 1 && !st.count(s))
		{
			st[s] = 1;
			rk ++;
		}
		//cout <<rk <<endl;
	}
	vector<cxy> v;
	for(auto [s, p] : mp)
		v.emplace_back(s, p.ff, p.se);
	sort(v.begin(), v.end(), cmp);
	for(auto [s, rk, c] : v)
		cout <<s <<endl;
	return 0;
}