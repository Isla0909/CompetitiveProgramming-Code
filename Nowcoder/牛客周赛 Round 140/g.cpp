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
	vector<int> p, siz, mask;

	void initial(int n, string &s)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);
		mask.assign(n + 1, 0);

		for(int i = 1; i <= n; i ++)
			mask[i] = 1 << (s[i] - 'A');
	}

	DSU(int n, string &s)
	{
		initial(n, s);
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
		mask[a] |= mask[b];
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
	string s; cin >>s;	
	s = " " + s;

	auto check = [&](int a, int b)
	{
		if(s[a] == 'A' || s[a] == 'B') return s[b] == 'A' || s[b] == 'B';
		return s[b] == 'C' || s[b] == 'D';
	};

	DSU dsu(n, s);
	vector<array<int, 2>> edges(m);
	vector<pii> ans; 
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		if(check(u, v))
		{
			if(!dsu.same(u, v)) 
			{
				ans.emplace_back(u, v);
				dsu.merge(u, v);
			}
		}
		edges[i] = {u, v};
	}

	bool f = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(dsu.find(i) != i) continue;
		if(dsu.size(i) == 1)
		{
			f = 0;
			break;
		}

		int s = dsu.mask[i];
		if((s >> 0 & 1) ^ (s >> 1 & 1)) f = 0;
		if((s >> 2 & 1) ^ (s >> 3 & 1)) f = 0;
	}
	if(!f)
	{
		cout <<"No" <<endl;
		return 0;
	}
	cout <<"Yes" <<endl;
	for(auto [u, v] : edges)
	{
		if(check(u, v)) continue;
		if(dsu.same(u, v)) continue;
		dsu.merge(u, v);
		ans.emplace_back(u, v);
	}
	for(auto [u, v] : ans)
		cout <<u <<" " <<v <<endl;
	return 0;
}
