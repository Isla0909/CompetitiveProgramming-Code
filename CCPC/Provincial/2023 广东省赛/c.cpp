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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<array<int, 2>> a(n);
		i64 sum = 0;
		for(int i = 0; i < n; i ++)
		{
			int x, y; cin >>x >>y;
			a[i] = {x, y};
			sum += y;
		}
		sort(a.begin(), a.end());

		i64 s1 = 0, s2 = 0;
		i64 t = sum / 2;
		for(int i = 0; i < n; i ++)
		{
			auto [x, y] = a[i];
			i64 c = min(t, (i64)y);
			s1 += c * x;
			t -= c;
		}
		t = sum / 2;
		for(int i = n - 1; i >= 0; i --)
		{
			auto [x, y] = a[i];
			i64 c = min(t, (i64)y);
			s2 += c * x;
			t -= c;
		}
		cout <<s2 - s1 <<endl;
	}
	return 0;
}
