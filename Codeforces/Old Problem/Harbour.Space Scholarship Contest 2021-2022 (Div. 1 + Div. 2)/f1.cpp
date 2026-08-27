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

template <typename T> 
struct Fenwick
{
	#define lowbit(x) (x & -x)

	int n;
	vector<T> tr;

	Fenwick() {}
	Fenwick(int n)
	{
		initial(n);
	}

	void initial(int n)
	{
		this -> n = n;
		tr.assign(n + 1, T{});
	}

	void add(int x, const T c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	T sum(int x)
	{
		T res = 0;
		for(int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	T rangeSum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}

	void rangeAdd(int l, int r, T c)
	{
		add(l, c);
		if(r + 1 <= n) add(r + 1, -c);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1);
	int V = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		V = max(V, a[i]);
	}
	Fenwick<i64> cnt(V), sum(V);
	i64 pre = 0, ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x = a[i];

		i64 A = 1LL * (i - 1) * x;
		for(int l = 1, r; l <= x; l = r + 1)
		{
			int q = x / l;
			r = x / q;
			i64 s = sum.rangeSum(l, r);
			A -= 1LL * q * s;
		}

		i64 B = pre;
		for(int l = x; l <= V; l += x)
		{
			int r = min(V, l + x - 1);
			i64 num = cnt.rangeSum(l, r);
			B -= 1LL * l * num;
		}
		ans += A + B;
		cout <<ans <<" \n"[i == n];

		cnt.add(x, 1);
		sum.add(x, x);
		pre += x;
	}
	return 0;
}
