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

constexpr int N = 5e3 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

struct DSU
{
	vector<int> p, siz;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);
	}

	DSU(int n)
	{
		initial(n);
	}

	int find(int x)
	{
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}

	void merge(int a, int b)
	{
		a = find(a), b = find(b);
		if(a == b) return ;

		siz[a] += siz[b];
		p[b] = a;
	}

	int size(int x)
	{
		return siz[find(x)];
	}
};

i64 C[N][N], g[2010][2010];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	C[0][0] = 1;
	for(int i = 1; i < N; i ++)
		for(int j = 0; j <= i; j ++)
		{
			if(j == 0) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		sort(a.begin() + 1, a.end());

		i64 ans = 0;
		for(int i = 2; i <= n; i ++)
		{
			int mid = (a[i] + 1) / 2;
			if(abs(a[1] - mid) > abs(a[i - 1] - mid)) ans = (ans + C[a[i]][a[1]]) % mod;
			else ans = (ans + C[a[i]][a[i - 1]]) % mod; 
		}
		cout <<ans <<endl;
	}
	return 0;
}
