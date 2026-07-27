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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	int a, b, c;
};

bool cmp(const cxy &a, const cxy &b)
{
	if(a.c != b.c) return a.c < b.c;
	return a.a < b.a;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<int> a(m + 1), b(m + 1), c(m + 1);
	vector<cxy> v;
	for(int i = 1; i <= m; i ++)
	{
		cin >>a[i] >> b[i];
		c[i] = a[i] - b[i];
		v.push_back({a[i], b[i], c[i]});
	}

	sort(v.begin(), v.end(), cmp);
	int idx = 0, ans = 0;

	// for(int i = 0; i < m; i ++)
	// 	cout <<v[i].a <<" " <<v[i].c <<endl;

	while(1)
	{
		if(idx == m || !n) break;

		if(n < v[idx].a)
		{
			idx ++;
			continue;
		}

		int delta = n - v[idx].a;
		int x = (delta) / v[idx].c + 1;

		n -= x * v[idx].c;

		//cout <<n <<" " <<x <<" " <<idx <<endl;

		ans += x;
		idx ++;
	}
	cout <<ans <<endl;
	return 0;
}