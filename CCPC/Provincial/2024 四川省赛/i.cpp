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

	int n, l, h; cin >>n >>l >>h;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i ++)
		cin >>x[i] >>y[i];

	set<pii> s; s.insert({0, 0});
	vector<array<int, 4>> v;
	for(int i = 0; i < n; i ++)
	{
		bool ok = 0;
		for(auto [a, b] : s)
		{
			int l1 = a, l2 = a + x[i];
			int h1 = b, h2 = b + y[i];

			bool f = 0;
			for(auto [x1, y1, x2, y2] : v)
			{
				
			}

			if(l1 >= 0 && l2 <= l && h1 >= 0 && h2 <= h && !f)
			{
				ok = 1;
				cout <<a <<" " <<b <<endl;
				s.erase({a, b});
				s.insert({l2, b}), s.insert({a, h2});
				break;
			}
		}
		if(!ok) cout <<-1 <<endl;
	}
	return 0;
}