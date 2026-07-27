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
typedef pair<int, string> pis;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int m, n; cin >>m >>n;
	vector<int> c(n);
	for(auto &x : c) cin >>x;

	int s = *min_element(c.begin(), c.end());

	vector<pis> v;
	for(int i = 0; i < m; i ++)
	{
		int x; string s; cin >>x >>s;
		v.emplace_back(x, s);
	}
	auto init = v;
	sort(v.begin(), v.end());
	map<string, vector<int>> mp;
	for(auto [x, s] : v)
	{
		mp[s].push_back(x);
	}

	vector<int> g;
	for(auto [_, v] : mp)
	{
		for(int i = v.size() - 1, cnt = s; i >= 0 && cnt; i --, cnt --)
			g.push_back(v[i]);
	}

	//tell(0, g);

	sort(g.begin(), g.end());

	auto get = [&](int x, vector<int> &h) -> i32
	{
		return h.size() - (upper_bound(h.begin(), h.end(), x) - h.begin());
	};

	for(int i = 0; i < m; i ++)
	{
		int x = get(init[i].ff, g), y = get(init[i].ff, mp[init[i].se]);
		y = min(y, s);
		//cout <<x <<" " <<y <<endl;
		if(y + 1 <= s) cout <<x + 1 <<endl;
		else cout <<x - y + s <<endl;
	}

	return 0;
}