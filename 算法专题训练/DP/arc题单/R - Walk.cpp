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
#include <cassert>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

struct matrix
{
	int x, y;
	vector <vector<int>> v;

	matrix(int x, int y) : x(x), y(y){
		v = vector <vector<int>>(x + 1, vector<int>(y + 1, 0));
	}

	void initial()
	{
		y = x;
		v = vector <vector<int>>(x + 1, vector<int>(x + 1, 0));
		for(int i = 1; i <= x; i ++) v[i][i] = 1;
	}

	void display()
	{
		for(int i = 1; i <= x; i ++)
			for(int j = 1; j <= y; j ++)
				cout <<v[i][j] <<" \n"[j == y];
	}

	friend matrix operator*(const matrix &a, const matrix &b)
	{
		assert(a.y == b.x);
		matrix ans(a.x, b.y);
		for(int i = 1; i <= a.x; i ++)
			for(int j = 1; j <= b.y; j ++)
				for(int k = 1; k <= a.y; k ++)
					ans.v[i][j] = (ans.v[i][j] + a.v[i][k] * b.v[k][j]) % mod;
		return ans;
	}
	friend matrix operator^(matrix x, int y)
	{
		assert(x.x == x.y);
		matrix ans(x.x, x.y);
		ans.initial();
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
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	matrix f(n, n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >>f.v[i][j];
	f = f ^ k;
	int res = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			res += f.v[i][j], res %= mod;
	cout <<res <<endl;
	return 0;
}