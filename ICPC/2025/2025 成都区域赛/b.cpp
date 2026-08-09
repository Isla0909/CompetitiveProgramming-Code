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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

struct Matrix
{
	int n, m;
	vector<vector<i64>> f;

	Matrix(int n = 1, int m = 1) : n(n), m(m)
	{
		f.assign(n + 1, vector<i64>(m + 1, 0));
	}

	Matrix(const vector<vector<i64>> &g)
	{
		n = g.size() - 1;
		m = g[0].size() - 1;
		f = g;
	}

	void clear()
	{
		for(int i = 1; i <= n; i ++)
			fill(f[i].begin(), f[i].end(), 0);
	}

	void initial(int c = -1)
	{
		if(c == -1) c = n;
		m = n = c;
		f.assign(c + 1, vector<i64>(c + 1, 0));
		for(int i = 1; i <= c; i ++)
			f[i][i] = 1;
	}

	void display()
	{
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cout <<f[i][j] <<" \n"[j == m];
	}

	//加法
	Matrix& operator+=(const Matrix &rhs)
	{
		assert(n == rhs.n && m == rhs.m);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				f[i][j] += rhs.f[i][j];
		return *this;
	}

	friend Matrix operator+(const Matrix &lhs, const Matrix &rhs)
    {
        Matrix res = lhs;
        res += rhs;
        return res;
    }


    //乘法
	friend Matrix operator*(const Matrix &a, const Matrix &b)
	{
		assert(a.m == b.n);
		Matrix ans(a.n, b.m);
		for(int i = 1; i <= a.n; i ++)
			for(int j = 1; j <= b.m; j ++)
				for(int k = 1; k <= a.m; k ++)
					ans.f[i][j] = max(ans.f[i][j] , a.f[i][k] + b.f[k][j]);
		return ans;	
	}

	Matrix& operator*=(const Matrix &rhs)
	{
		*this = *this * rhs;
		return *this;
	}

	//快速幂
	friend Matrix operator^(Matrix x, int y)
	{
		assert(x.n == x.m);
		int c = x.n;
		Matrix ans(c, c);
		while(y)
		{
			if(y & 1) ans = ans * x;

			x = x * x;
			y >>= 1; 
		}
		return ans;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k, R; cin >>n >>m >>k >>R;
		vector<int> a(n), c(n);
		for(int i = 0; i < n; i ++) 
			cin >>a[i] >>c[i];

		vector<i64> A(1 << n), C(1 << n);
		for(int s = 0; s < (1 << n); s ++)
		{
			for(int i = 0; i < n; i ++)
			{
				if(s >> i & 1)
				{
					A[s] += a[i];
					C[s] += c[i];
				}
			}
		}
		Matrix M(1 << n, 1 << n);
		for(int s = 0; s < (1 << n); s ++)
			for(int t = 0; t < (1 << n); t ++)
			{
				int x = __builtin_popcount(s & t);
				if(C[s] + k * x <= m)
				{
					M.f[t + 1][s + 1] = A[s];
				}
			}

		Matrix res = (M ^ R);
		i64 ans = 0;
		for(int i = 0; i < (1 << n); i ++)
			ans = max(ans, res.f[1][i + 1]);
		cout <<ans <<endl;
	}
	return 0;
}
