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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int quick_pow(int a, i64 b, int p = mod)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res % p;
}

int inv(int x)
{
	return quick_pow(x, mod - 2, mod);
}

int p[N], d[N];

int find(int x)
{
	if(x != p[x])
	{
		int fa = p[x];
		p[x] = find(p[x]);
		d[x] ^= d[fa];
	}
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<char>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];
		
		for(int i = 1; i <= n; i ++)
			p[i] = i, d[i] = 0;

		bool ok = 1;
		int mid = (m + 1) / 2;
		for(int j = 1; j <= mid && ok; j ++)
		{
			vector<pii> v;
			bool f = false;
			for(int i = 1; i <= n && ok; i ++)
			{
				char l = g[i][j], r = g[i][m - j + 1];
				if(l == r)
				{
					if(l == '0') continue;
					if(f || v.size()) ok = false;
					if(l == '1') f = true;
				}
				else
				{
					if(f) ok = false;

					v.emplace_back(i, (l == '1'));
				}
			}
			if(v.size() > 2) ok = false;

			if(v.size() == 2)
			{
				auto [a, s1] = v[0]; auto [b, s2] = v[1];
				int pa = find(a), pb = find(b);
				int w = s1 ^ s2 ^ 1;
				if(pa == pb)
				{
					if((d[a] ^ d[b]) != w) ok = false;
				}
				else
				{
					p[pa] = pb;
					d[pa] = d[a] ^ d[b] ^ w;
				}
			}
		}
		if(!ok)
		{
			cout <<0 <<endl;
			continue;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			cnt += p[i] == i;
		cout <<quick_pow(2, cnt) <<endl;
	}
	return 0;
}
