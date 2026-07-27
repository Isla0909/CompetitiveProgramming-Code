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

	int n, m; cin >>n >>m;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++) 
	{
		cin >>a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}

	int len = n / min(n, (int)sqrt(m));
	vector<int> bel(n + 1);
	for(int i = 1; i <= n; i ++)
		bel[i] = (i - 1) / len + 1;

	vector<array<int, 3>> query(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int l, r; cin >>l >>r;
		query[i] = {i, l, r};
	}
	sort(query.begin() + 1, query.end(), [&](auto &a, auto &b)
	{
		if(bel[a[1]] != bel[b[1]]) return bel[a[1]] < bel[b[1]];
		return a[2] < b[2];
	});

	vector<int> ans(m + 1);
	for(int x = 1; x <= m; )
	{
		int y = x;
		while(y <= m && bel[query[y][1]] == bel[query[x][1]]) y ++;

		int R = min(n, len * bel[query[x][1]]);
		while(x < y && query[x][2] <= R)
		{	
			int res = 0;
			auto [id, l, r] = query[x];
			for(int i = l; i <= r; i ++)
				for(int j = i; j <= r; j ++)
					res = max(res, pre[j] ^ pre[i - 1]);
			ans[id] = res;
			x ++;
		}
		int i = R, j = R + 1, res = 0;
		while(x < y)
		{
			auto [id, l, r] = query[x];
			int s = 0;
			while(i < r)
			{
				res ^= a[++ i];
				s = max(s, res);
			}
			int backup = res;
			while(j > l)
			{
				res ^= a[-- j];
				s = max(s, res);
			}
			ans[id] = s;
			j = R + 1, res = backup;
			x ++;
		}
	}
	for(int i = 1; i <= m; i ++)
		cout <<ans[i] <<endl;
	return 0;
}
