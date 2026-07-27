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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct Fenwick
{
	int n;
	vector<int> tr;

	#define lowbit(x) (x & -x)

	Fenwick(int n)
	{
		this->n = n;
		tr.assign(n + 1, 0);
	}

	void add(int x, int c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] ^= c;
	}

	int get(int x)
	{
		int res = 0;
		for(int i = x; i; i -= lowbit(i))
			res ^= tr[i];
		return res;
	}

	int rangeXor(int l, int r)
	{
		return get(r) ^ get(l - 1);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}

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

	auto b = a;
	sort(b.begin() + 1, b.end());
	b.erase(unique(b.begin() + 1, b.end()), b.end());

	auto find = [&](int x) -> int
	{
		return lower_bound(b.begin() + 1, b.end(), x) - (b.begin() + 1) + 1;
	};

	Fenwick bit(n + 1);
	vector<int> ans(q + 1), lst(n + 1, -1);
	int j = 0;
	for(int i = 1; i <= q; i ++)
	{
		auto [l, r, id] = query[i];
		while(j + 1 <= r)
		{
			j ++;
			int x = a[j], c = find(x);
			if(lst[c] == -1)
			{
				lst[c] = j;
				bit.add(j, x);
			}
			else
			{
				bit.add(lst[c], x);
				lst[c] = j;
				bit.add(j, x);
			}
		}
		ans[id] = pre[r] ^ pre[l - 1] ^ bit.rangeXor(l, r);
	}
	for(int i = 1; i <= q; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
