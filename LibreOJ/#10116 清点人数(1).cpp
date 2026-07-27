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

struct Info
{
	int val = 0;
};

Info operator+(const Info &a, const Info &b)
{
	return {a.val + b.val};
};

struct SegmentTree
{
	int n;
	vector<Info> info;
	SegmentTree(int n_) : n(n_), info(4 * n + 1) {}

	void pushup(int u)
	{
		info[u] = info[u << 1] + info[u << 1 | 1];
	}

	void modify(int u, int l, int r, int pos, const int &v)
	{
		if(r == l)
		{
			assert(pos == l);
			info[u].val += v;
			return ;
		}

		int mid = l + r >> 1;
		if(pos <= mid) modify(u << 1, l, mid, pos, v);
		else modify(u << 1 | 1, mid + 1, r, pos, v);
		pushup(u);
	}

	Info query(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return info[u];

		int mid = l + r >> 1;

		Info res = {0};
		if(ql <= mid) res = res + query(u << 1, l, mid, ql, qr);
		if(qr >= mid + 1) res = res + query(u << 1 | 1, mid + 1, r, ql, qr);
		return res; 
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	SegmentTree seg(n);

	while(q --)
	{
		char op; cin >>op;
		if(op == 'A')
		{
			int x; cin >>x;
			cout <<seg.query(1, 1, n, 1, x).val <<endl;
		}
		else if(op == 'B')
		{
			int m, p; cin >>m >>p;
			seg.modify(1, 1, n, m, p);
		}
		else
		{
			int m, p; cin >>m >>p;
			seg.modify(1, 1, n, m, -p);
		}
	}
	return 0;
}