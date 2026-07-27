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

	int n; cin >>n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) cin >>a[i];

	auto aa = a;

	sort(a.begin(), a.end());

	auto b = a;
	b.erase(unique(b.begin(), b.end()), b.end());

	auto get = [&](int l, int r) -> int//范围[l, r]之间有多少不同的数
	{
		auto t1 = lower_bound(b.begin(), b.end(), l) - b.begin();
		auto t2 = upper_bound(b.begin(), b.end(), r) - b.begin();
		return t2 - t1;
	};

	int ans = a[0], M = 1;
	for(int i = 0; i < n; i ++)
	{
		int l = a[i], r = a[i] + n - 1;
		int c = get(l, r);
		if(c > M)
		{
			ans = a[i];
			M = c;
		}
	}
	//cout <<ans <<" " <<M <<endl;
	map<int, int> mp;
	int l = ans, r = ans + n - 1;
	vector<int> v; a = aa;
	for(int i = 0; i < n; i ++)
	{
		if(a[i] >= l && a[i] <= r)
		{
			//cout <<i <<" enter " <<a[i] <<endl;
			if(mp.count(a[i])) v.push_back(i + 1);
			else mp[a[i]] = 1;
		}
		else v.push_back(i + 1);
	}
	vector<pii> res;
	for(int i = l; i <= r; i ++)
	{
		if(!mp[i])
		{
			assert(v.size() != 0);
			auto p = v.back(); v.pop_back();
			res.emplace_back(p, i);
		}
	}
	cout <<res.size() <<endl;
	for(auto [x, y] : res)
		cout <<x <<" " <<y <<endl;
	return 0;
}
