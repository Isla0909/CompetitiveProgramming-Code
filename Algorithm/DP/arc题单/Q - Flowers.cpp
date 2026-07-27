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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

	T rangeSum(int l, int r)
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

};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;

	vector<int> h(n + 1), a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>h[i];
	for(int i = 1; i <= n; i ++) cin >>a[i];

	int ans = -1;
	Fenwick<int> bit(n);
	for(int i = 1; i <= n; i ++)
	{
		int res = bit.max_query(h[i] - 1) + a[i];
		ans = max(ans, res);
		bit.max_update(h[i], res);
	}
	cout <<ans <<endl;
	return 0;
}