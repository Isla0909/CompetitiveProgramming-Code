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

	int n, m; cin >>n >>m;
	int len = sqrt(n);
	vector<int> bel(n + 1);
	for(int i = 1; i <= n; i ++)
		bel[i] = (i - 1) / len + 1;

	int cnt = bel[n];
	vector<i64> add(cnt + 1), sum(cnt + 1);
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		sum[bel[i]] += a[i];
	}

	auto change = [&](int l, int r, i64 x) -> void
	{
		if(bel[l] == bel[r])
		{
			int c = bel[l];
			for(int i = l; i <= r; i ++)
			{
				a[i] += x;
				sum[c] += x;
			}
			return ;
		}
		int i = l, j = r;
		while(bel[i] == bel[l]) a[i] += x, sum[bel[l]] += x, i ++;
		while(bel[j] == bel[r]) a[j] += x, sum[bel[r]] += x, j --;
		for(int k = bel[i]; k <= bel[j]; k ++)
		{
			add[k] += x;
			sum[k] += x * len;
		}
	};

	auto query = [&](int l, int r) -> i64
	{
		i64 res = 0;
		if(bel[l] == bel[r])
		{
			int c = bel[l];
			for(int i = l; i <= r; i ++)
				res += a[i] + add[c];
		}
		else
		{
			int i = l, j = r;
			while(bel[i] == bel[l]) res += a[i] + add[bel[l]], i ++;
			while(bel[j] == bel[r]) res += a[j] + add[bel[r]], j --;
			for(int k = bel[i]; k <= bel[j]; k ++)
				res += sum[k];
		}
		return res;
	};
	//tell(1, bel);
	while(m --)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int l, r; i64 x; cin >>l >>r >>x;
			change(l, r, x);
		}
		else if(op == 2)
		{
			i64 x; cin >>x;
			a[1] += x;
			sum[1] += x;
		}
		else if(op == 3)
		{
			i64 x; cin >>x;
			a[1] -= x;
			sum[1] -= x;
		}
		else if(op == 4)
		{
			int l, r; cin >>l >>r;
			cout <<query(l, r) <<endl;
		}
		else cout <<a[1] <<endl;

		// for(int i = 1; i <= n; i ++)
		// 	cout <<a[i] + add[bel[i]] <<" \n"[i == n];
	}


	return 0;
}