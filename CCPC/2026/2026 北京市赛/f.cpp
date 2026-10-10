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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> p(n + 1), ls(n + 1), rs(n + 1);
	vector<int> stk;
	for(int i = 1; i <= n; i ++) 
	{
		cin >>p[i];

		int last = 0;
		while(stk.size() && p[stk.back()] > p[i])
		{
			last = stk.back();
			stk.pop_back();
		}

		if(stk.size()) rs[stk.back()] = i;

		ls[i] = last;
		stk.push_back(i);
	}

	int root = stk.front();
	vector<i64> siz(n + 1), sum(n + 1);
	vector<i64> mx(n + 1), mn(n + 1);
	[&](this auto &&self, int u) -> void
	{
		int l = ls[u], r = rs[u];

		if(l) self(l);
		if(r) self(r);

		siz[u] = siz[l] + siz[r] + 1;
		sum[u] = sum[l] + sum[r] + p[u];

		i64 A = (siz[l] + 1) * (p[u] + sum[r]);
		i64 B = (siz[r] + 1) * (p[u] + sum[l]);

		mx[u] = mx[l] + mx[r] + max(A, B);
		mn[u] = mn[l] + mn[r] + min(A, B);
	}(root);
	cout <<mx[root] <<" " <<mn[root] <<endl;
	return 0;
}
