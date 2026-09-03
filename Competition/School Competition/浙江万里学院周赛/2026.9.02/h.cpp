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

struct SegmentTree
{
	struct Info
	{
		int c4, c7;
		int ans1, ans2;

		Info operator+(const Info &rhs) const
		{
			Info res;
			res.c4 = c4 + rhs.c4;
			res.c7 = c7 + rhs.c7;
			res.ans1 = max(c4 + rhs.ans1, ans1 + rhs.c7);
			res.ans2 = max(c7 + rhs.ans2, ans2 + rhs.c4);
			return res;
		}
	};

	int n;
	string s;
	vector<Info> tr;
	vector<int> tag;

	SegmentTree(const string &s)
	{
		this -> s = s;
		n = s.size();
		tr.resize(4 * n + 10);
		tag.resize(4 * n + 10);
		build(1, 1, n);
	}

	void pushup(int u)
	{
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}

	void build(int u, int l, int r)
	{
		if(l == r)
		{
			tr[u].c4 = (s[l - 1] == '4');
			tr[u].c7 = 1 - tr[u].c4;
			tr[u].ans1 = tr[u].ans2 = 1;
			return ; 
		}
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}


	void apply(int u)
	{
		swap(tr[u].c4, tr[u].c7);
		swap(tr[u].ans1, tr[u].ans2);
		tag[u] ^= 1;
	}

	void pushdown(int u)
	{
		if(!tag[u]) return ;

		apply(u << 1);
		apply(u << 1 | 1);
		tag[u] = 0;
	}

	void modify(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr)
		{
			apply(u);
			return ;
		}

		pushdown(u);

		int mid = l + r >> 1;
		if(ql <= mid) modify(u << 1, l, mid, ql, qr);
		if(qr >= mid + 1) modify(u << 1 | 1, mid + 1, r, ql, qr);
		pushup(u);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	string s; cin >>s;

	SegmentTree seg(s);
	while(q --)
	{
		string op; cin >>op;
		if(op == "count") cout <<seg.tr[1].ans1 <<endl;
		else
		{
			int l, r; cin >>l >>r;
			seg.modify(1, 1, n, l, r);
		}
	}
	return 0;
}
