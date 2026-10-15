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

constexpr int mod = 998244353;

struct Matrix
{
	i64 f[5][5]{};

	void initial()
	{
		*this = Matrix{};
		for(int i = 1; i <= 4; i ++)
			f[i][i] = 1;
	}

	void display()
	{
		for(int i = 1; i <= 4; i ++)
			for(int j = 1; j <= 4; j ++)
				cout <<f[i][j] <<" \n"[j == 4];
	}

    //乘法
	friend Matrix operator*(const Matrix &a, const Matrix &b)
	{
		Matrix ans;
		for(int i = 1; i <= 4; i ++)
			for(int j = 1; j <= 4; j ++)
				for(int k = 1; k <= 4; k ++)
					ans.f[i][j] = (ans.f[i][j] + a.f[i][k] * b.f[k][j]) % mod;
		return ans;	
	}

	Matrix& operator*=(const Matrix &rhs)
	{
		*this = *this * rhs;
		return *this;
	}
};

struct SegmentTree
{
	struct Info
	{
		array<i64, 5> s{};

		friend Info operator+(const Info &a, const Info &b)
		{
			Info c;
			for(int i = 1; i <= 4; i ++)
				c.s[i] = (a.s[i] + b.s[i]) % mod;
			return c;
		}

		void apply(const Matrix &v)
		{
			array<i64, 5> t{};
			for(int j = 1; j <= 4; j ++)
			{
				i64 res = 0;
				for(int i = 1; i <= 4; i ++)
					res += s[i] * v.f[i][j];
				t[j] = res % mod;
			}
			s = t;
		}
	};

	struct Tag
	{
		Matrix M;
		bool lazy = false;

		Tag()
		{
			M.initial();
		}
	};

	int n;
	vector<array<int, 3>> w;
	vector<Info> tr;
	vector<Tag> tag;

	SegmentTree(const vector<array<int, 3>> &a)
	{
		n = a.size() - 1;
		w = a;
		tr.resize(4 * n + 10);
		tag.resize(4 * n + 10);
		build(1, 1, n);
	}

	void pushup(int u)
	{
		tr[u] = tr[u << 1] + tr[u << 1 | 1];
	}

	void apply(int u, const Matrix &v)
	{
		tr[u].apply(v);

		if(tag[u].lazy) tag[u].M *= v;
		else tag[u].M = v;

		tag[u].lazy = true;
	}

	void pushdown(int u)
	{
		if(!tag[u].lazy) return ;

		apply(u << 1, tag[u].M);
		apply(u << 1 | 1, tag[u].M);

		tag[u] = Tag{};
	}

	void build(int u, int l, int r)
	{
		if(l == r)
		{
			tr[u].s = {-1, w[l][0], w[l][1], w[l][2], 1};
			return ;
		}
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}

	void modify(int u, int l, int r, int ql, int qr, Matrix &v)
	{
		if(l >= ql && r <= qr)
		{
			apply(u, v);
			return ;
		}

		pushdown(u);
		int mid = l + r >> 1;
		if(ql <= mid) modify(u << 1, l, mid, ql, qr, v);
		if(qr >= mid + 1) modify(u << 1 | 1, mid + 1, r, ql, qr, v);
		pushup(u);
	}

	void modify(int ql, int qr, Matrix &v)
	{
		return modify(1, 1, n, ql, qr, v);
	}

	Info query(int u, int l, int r, int ql, int qr)
	{
		if(l >= ql && r <= qr) return tr[u];

		pushdown(u);
		int mid = l + r >> 1;
		if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
		else if(qr <= mid) return query(u << 1, l, mid, ql, qr);
		return query(u << 1, l, mid, ql, qr) + query(u << 1 | 1, mid + 1, r, ql, qr);
	}

	Info query(int ql, int qr)
	{
		return query(1, 1, n, ql, qr);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<array<int, 3>> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>a[i][0] >>a[i][1] >>a[i][2];

	SegmentTree seg(a);

	int q; cin >>q;
	while(q --)
	{
		int op; cin >>op;
		if(op == 7)
		{
			int l, r; cin >>l >>r;
			auto res = seg.query(l, r);
			cout <<res.s[1] <<" " <<res.s[2] <<" " <<res.s[3] <<endl;
			continue;
		}

		int l, r, v; cin >>l >>r;
		if(op >= 4) cin >>v;

		Matrix M;
		M.initial();
		if(op == 1) M.f[2][1] = 1;
		else if(op == 2) M.f[3][2] = 1;
		else if(op == 3) M.f[1][3] = 1;
		else if(op == 4) M.f[4][1] = v;
		else if(op == 5) M.f[2][2] = v;
		else M.f[3][3] = 0, M.f[4][3] = v; 

		seg.modify(l, r, M);
	}
	return 0;
}
