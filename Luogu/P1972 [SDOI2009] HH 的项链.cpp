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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct Fenwick
{
	int n;
	vector<int> tr;

	#define lowbit(x) (x & -x)

	Fenwick(int n = 0)
	{
		initial(n);
	}

	void initial(int n)
	{
		this->n = n;
		tr.assign(n + 1, 0);
	}

	void add(int x, int c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	i64 sum(int x)
	{
		i64 ans = 0;
		for(int i = x; i; i -= lowbit(i))
			ans += tr[i];
		return ans;
	}

	i64 rangeSum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<int> lst(N, -1);
	int q; cin >>q;
	vector<array<int, 3>> query(q + 1);
	for(int i = 1; i <= q; i ++)
	{
		int l, r; cin >>l >>r;
		query[i] = {l, r, i};
	}

	sort(query.begin() + 1, query.end(), [&](auto a, auto b)
	{
		return a[1] < b[1];
	});

	Fenwick bit(N);

	int j = 1;
	vector<int> ans(q + 1);
	for(int i = 1; i <= q; i ++)
	{
		auto [l, r, id] = query[i];
		while(j <= r)
		{
			int x = a[j];
			if(lst[x] == -1)
			{
				lst[x] = j;
				bit.add(j, 1);
			}
			else
			{
				bit.add(lst[x], -1);
				lst[x] = j;
				bit.add(j, 1);
			}
			j ++;
		}
		ans[id] = bit.rangeSum(l, r);
	}
	for(int i = 1; i <= q; i ++)
		cout <<ans[i] <<endl;
	return 0;
}