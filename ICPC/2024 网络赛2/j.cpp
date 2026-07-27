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
#define int long long
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

struct  cxy
{
	int w, v, c;
};

bool cmp(const cxy &a, const cxy &b)
{
	if(a.c * b.w == b.c * a.w) return a.w < b.w;
	return 1.0 * a.c / a.w < 1.0 * b.c / b.w;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<cxy> v(n);
	for(int i = 0; i < n; i ++)
		cin >>v[i].w >>v[i].v >>v[i].c;

	sort(v.begin(), v.end(), cmp);

	i64 ans = 0, now = 0;
	for(int i = 0; i < n; i ++)
	{
		auto [w, V, c] = v[i];
		//cout <<w <<" " <<V <<" " <<c <<endl;
		ans += 1LL * V - 1LL * c * now;

		now += w;
	}
	cout <<ans <<endl;
	return 0;
}