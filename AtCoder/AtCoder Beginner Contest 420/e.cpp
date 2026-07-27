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

struct DSU
{
	vector<int> p, siz;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 0);
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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	DSU dsu(n);
	vector<bool> st(n + 1);
	vector<int> a(n + 1);

	bool f = 0;
	while(m --)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int a, b; cin >>a >>b;
			dsu.merge(a, b);
		}
		else if(op == 2)
		{
			int x; cin >>x;
			if(!a[x])
			{
				st[dsu.find(x)] = 1;
				dsu.siz[dsu.find(x)] ++;
			}
			else
			{
				dsu.siz[dsu.find(x)] --;
				if(!dsu.siz[dsu.find(x)]) st[dsu.find(x)] = 0;
			}
			a[x] ^= 1;
		}
		else
		{
			int x; cin >>x;
			//cout <<dsu.find(x) <<endl;
			if(dsu.siz[dsu.find(x)]) cout <<"Yes" <<endl;
			else cout <<"No" <<endl;
		}
	}
	return 0;
}