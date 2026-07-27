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

i64 quick_pow(i64 a, int b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

struct cxy
{
	int x, d;
	cxy() {}
	cxy(int x, int d) : x(x), d(d) {}
	bool operator>(const cxy &T) const
	{
	//	if(d != T.d) return d > T.d;
		return x > T.x;
	}
};

bool cmp(const cxy &a, const cxy &b)
{
	if(a.d != b.d) return a.d < b.d;
	return a.x < b.x;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector<int> a(n + 1), d(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		d[i] = __lg(a[i]);
	}

	int s = *max_element(d.begin() + 1, d.end());
	int need = 0;
	for(int i = 1; i <= n; i ++)
		need += s - d[i];
	// if(need <= k)
	// {
	// 	k -= need;
	// 	vector<int> v;
	// 	sort(a.begin() + 1, a.end());
	// 	int p = k / n, q = k % n;
	// 	i64 ans = 0;
	// 	for(int i = 1; i <= n; i ++)
	// 		ans = (ans + a[i] * quick_pow(2, s + p + (i <= q) - __lg(a[i])) % mod) % mod; 
	// 	cout <<ans <<endl;
	// }
	// else
	{
		priority_queue<cxy, vector<cxy>, greater<>> q;
		for(int i = 1; i <= n; i ++)
			q.emplace(a[i], d[i]);
		while(k --)
		{
			auto [x, d] = q.top(); q.pop();
			q.emplace(x * 2, d);
		}
		i64 ans = 0;
		while(q.size())
		{
			auto [x, d] = q.top(); q.pop();
			ans = (ans + x) % mod;
		}
		cout <<ans <<endl;
	}
	return 0;
}
