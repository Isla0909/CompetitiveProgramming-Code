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

int p[N], siz[N], deg[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void merge(int a, int b)
{
	int pa = find(a), pb = find(b);
	if(pa == pb) return ;

	if(siz[pa] < siz[pb]) swap(pa, pb);

	siz[pa] += siz[pb];
	p[pb] = pa;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	for(int i = 1; i <= n; i ++)
		p[i] = i, siz[i] = 1;
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >>u >>v;
		deg[u] ++, deg[v] ++;
		merge(u, v);
	}	

	vector<bool> ok(n + 1, true);
	for(int i = 1; i <= n; i ++)
	{
		int x = find(i);
		if(deg[i] != 2) ok[x] = false;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += (p[i] == i && ok[i]);
	cout <<ans <<endl;
	return 0;
}
