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

template <typename T> 
struct Fenwick
{
	int n;
	vector<T> tr;

	#define lowbit(x) (x & -x)

	void initial(int n_)
	{
		n = n_;
		tr.assign(n + 1, T{});
	}

	Fenwick(int n_ = 0)
	{
		initial(n_);
	}

	void add(int x, const T &c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	T sum(int x)
	{
		T ans{};
		for(int i = x; i; i -= lowbit(i))
			ans += tr[i];
		return ans;
	}

	T rangeSum(int l, int r)//闭区间[l, r]之和
	{
		return sum(r) - sum(l - 1);
	}

	int select(const T &k)
	{
		int x = 0;
		T cur{};
		for(int i = 1 << __lg(n); i; i /= 2)
		{
			if(x + i <= n && cur + tr[x + i] <= k)
			{
				x += i;
				cur += tr[x];
			}
		}
		return x;
	}

	void max_update(int x, const T &c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] = max(tr[i], c);
	}

	T max_query(int x)
	{
		T ans{};
		for(int i = x; i; i -= lowbit(i))
			ans = max(ans, tr[i]);
		return ans;
	}

	i64 calc(vector<T> &a)
	{
		tr.assign(n + 1, T{});
		
		vector<T> b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		auto find = [&](T x) -> int
		{
			return lower_bound(b.begin(), b.end(), x) - b.begin();
		};

		i64 ans = 0;
		for(int i = 0; i < a.size(); i ++)
		{
			int x = find(a[i]) + 1;
			add(x, 1);
			ans += i + 1 - sum(x);
		}
		return ans;
	}
};
//开的时候不需要再Fenwick<int> bit(n + 1)了

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t; cin >>n >>t;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		a[i] = 301 - x;
	}

	Fenwick<int> bit(300);
	int lim = min(n, t);
	for(int i = 0; i < lim; i ++)
		for(int j = 1; j <= n; j ++)
		{
			int c = bit.max_query(a[j]) + 1;
			bit.max_update(a[j], c);
		}
	int ans1 = bit.max_query(300);
	if(t > n)
	{
		for(int j = 1; j <= n; j ++)
		{
			int c = bit.max_query(a[j]) + 1;
			bit.max_update(a[j], c);
		}
		int ans2 = bit.max_query(300);
		ans1 += (t - n) * (ans2 - ans1);
	}
	cout <<ans1 <<endl;
	return 0;
}
