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

struct Fenwick
{
	#define lowbit(x) (x & -x)

	int n;
	vector<i64> tr;

	Fenwick(int n) : n(n), tr(n + 1) {}

	void add(int x, i64 c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	void rangeAdd(int l, int r, i64 c)
	{
		add(l, c);
		if(r + 1 <= n) add(r + 1, -c);
	}

	i64 query(int x)
	{
		i64 res = 0;
		for(int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >>n >>m >>q;
	vector<array<int, 4>> query(q + 1);
	vector<int> last(n + 1);
	vector<vector<pii>> vec(q + 1);
	for(int i = 1; i <= q; i ++)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int l, r, x; cin >>l >>r >>x;
			query[i] = {op, l, r, x};
		}
		else if(op == 2)
		{
			int row, x; cin >>row >>x;
			query[i] = {op, row, x, -1};
			last[row] = i;
		}
		else
		{
			int row, col; cin >>row >>col;
			query[i] = {op, row, col, -1};
			vec[last[row]].emplace_back(i, col);
		}
	}

	vector<i64> ans(q + 1);
	Fenwick bit(m);
	for(int i = 1; i <= q; i ++)
	{
		auto [op, a, b, x] = query[i];
		if(op == 1) bit.rangeAdd(a, b, x);
		else if(op == 2)
		{
			int val = b;
			for(auto [id, col] : vec[i])
				ans[id] = -bit.query(col) + val;
		}
		else
		{
			int col = b;
			ans[i] += bit.query(col);
			cout <<ans[i] <<endl;
		}
	}
	return 0;
}
