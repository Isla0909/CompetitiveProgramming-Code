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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7, P = 131;

u64 p[N];

vector<u64> get(string &s)
{
	int n = s.size();
	vector<u64> h(n);
	for(int i = 1; i < n; i ++)
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;
	return h;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < N; i ++)
		p[i] = p[i - 1] * P;

	string s; cin >>s;
	int len = s.size();
	s += s; s = ' ' + s;

	auto H = get(s);
	auto fun = [&](vector<u64> &h, int l, int r) -> u64
	{
		return h[r] - h[l - 1] * p[r - l + 1];
	};

	set<u64> S;
	for(int i = 1; i + len - 1 < s.size(); i ++)
	{
		u64 x = fun(H, i, i + len - 1);
		S.insert(x);
	}

	int q; cin >>q;
	while(q --)
	{
		i64 ans = 0;
		string t; cin >>t;
		t = ' ' + t;
		auto h = get(t);
		for(int i = 1; i + len - 1 < t.size(); i ++)
		{
			u64 x = fun(h, i, i + len - 1);
			if(S.count(x)) ans ++;
		}
		cout <<ans <<endl;
	}
	return 0;
}
