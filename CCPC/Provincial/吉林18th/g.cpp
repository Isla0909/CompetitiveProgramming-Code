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
		i64 n; cin >>n;
		vector<int> a(3), b(3);
		for(int i = 0; i < 3; i ++) cin >>a[i];
		for(int i = 0; i < 3; i ++) cin >>b[i];

		auto v1 = a, v2 = b;
		int res1 = 0; int t = n;
		for(int i = 0; i < 3; i ++)
		{
			int c = min(a[i], b[(i + 1) % 3]);
			a[i] -= c, b[(i + 1) % 3] -= c;
			res1 += c; t -= c;
		}
		for(int i = 0; i < 3; i ++)
		{
			int c = min(a[i], b[i]);
			a[i] -= c, b[i] -= c;
			t -= c;
		}
		res1 -= t;

		a = v1, b = v2;
		// tell(0, a), tell(0, b);
		int res2 = 0; t = n;
		for(int i = 0; i < 3; i ++)
		{
			int c = min(a[i], b[(i - 1 + 3) % 3]);
			a[i] -= c, b[(i - 1 + 3) % 3] -= c;
			res2 -= c; t -= c;
		}
		for(int i = 0; i < 3; i ++)
		{
			int c = min(a[i], b[i]);
			a[i] -= c, b[i] -= c;
			t -= c;
		}
		res2 += t;
		cout <<res1 <<" " <<res2 <<endl;
	}

	return 0;
}