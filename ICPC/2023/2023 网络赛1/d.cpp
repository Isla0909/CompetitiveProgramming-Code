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
	vector<int> p, siz, cnt;

	void initial(int n)
	{
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);

		siz.assign(n + 1, 1);//点
		cnt.assign(n + 1, 0);//边
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
		
		if(a == b)
		{
			cnt[a] ++;
			return ;
		}

		siz[a] += siz[b];
		cnt[a] += cnt[b] + 1;
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
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		dsu.merge(u, v);
	}
	i64 ans = 0; bool f = 0;
	vector<int> vec;
	for(int i = 1; i <= n; i ++)
	{
		if(i == dsu.find(i))
		{
			int v = dsu.siz[i], e = dsu.cnt[i];
			if(v * (v - 1) / 2 != e)
			{
				f = 1;
				ans += 1LL * v * (v - 1) / 2 - e;
			}
			vec.push_back(v);
		}
	}
	if(f) cout <<ans <<endl;
	else
	{
		sort(vec.begin(), vec.end());
		cout <<1LL * vec[0] * vec[1] <<endl;
	}
	return 0;
}