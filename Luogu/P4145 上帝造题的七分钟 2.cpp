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
	int len = (int)sqrt(n);
	vector<int> bel(n + 1);
	for(int i = 1; i <= n; i ++)
		bel[i] = (i - 1) / len + 1;

	int cnt = bel[n];
	vector<int> add(cnt + 1);
	vector<i64> a(n + 1), sum(cnt + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		sum[bel[i]] += a[i];
	}

	auto change = [&](int l, int r) -> void
	{
		if(bel[l] == bel[r])
		{
			int c = bel[l];
			if(add[c] >= 6) return ;
			for(int i = l; i <= r; i ++)
			{
				sum[c] -= a[i];
				a[i] = (i64)sqrt(a[i]);
				sum[c] += a[i];
			}
			return ;
		}

		int i = l, j = r;
		while(bel[i] == bel[l])
		{
			sum[bel[l]] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[bel[l]] += a[i];
			i ++;
		}
		while(bel[j] == bel[r])
		{
			sum[bel[r]] -= a[j];
			a[j] = (i64)sqrt(a[j]);
			sum[bel[r]] += a[j];
			j --;
		}

		for(int k = bel[i]; k <= bel[j]; k ++)
		{
			if(add[k] >= 6) continue;
			add[k] ++;

			for(int c = (k - 1) * len + 1; c <= min(n, k * len); c ++)
			{
				sum[k] -= a[c];
				a[c] = (i64)sqrt(a[c]);
				sum[k] += a[c];
			}
		}
	};

	auto query = [&](int l, int r) -> i64
	{
		i64 res = 0;
		if(bel[l] == bel[r])
		{
			for(int i = l; i <= r; i ++)
				res += a[i];
		}
		else
		{
			int i = l, j = r;
			while(bel[i] == bel[l]) res += a[i], i ++;
			while(bel[j] == bel[r]) res += a[j], j --;
			for(int k = bel[i]; k <= bel[j]; k ++)
				res += sum[k];
		}
		return res;
	};

	int q; cin >>q;
	while(q --)
	{
		int op, l, r; cin >>op >>l >>r;
		if(l > r) swap(l, r);

		if(op ^ 1) change(l, r);
		else cout <<query(l, r) <<endl;
	}

	return 0;
}