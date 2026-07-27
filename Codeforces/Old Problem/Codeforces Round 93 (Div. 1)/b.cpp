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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7, P = 131;

u64 p[N], h[N];

u64 get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

bool equal(int l1, int r1, int l2, int r2)
{
	return get(l1, r1) == get(l2, r2);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < N; i ++)
		p[i] = p[i - 1] * P;

	string s; cin >>s;
	int n = s.size();
	s = " " + s;
	for(int i = 1; i <= n; i ++)
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;

	vector<int> v;
	for(int i = 1; i <= n; i ++)
		if(equal(1, i, n - i + 1, n))
			v.push_back(i);

	auto check = [&](int x) -> bool
	{
		u64 tar = get(1, x);
		for(int i = 2; i + x - 1 < n; i ++)
			if(get(i, i + x - 1) == tar) return true;
		return false;
	};

	int ans = 0;
	int l = -1, r = v.size();
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(v[mid])) l = mid;
		else r = mid;
	}
	if(l == -1) cout <<"Just a legend" <<endl;
	else cout <<s.substr(1, v[l]) <<endl;
	return 0;
}
