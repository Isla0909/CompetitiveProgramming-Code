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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<i64, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<i64> &v)
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

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<array<int, 2>> v(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >>v[i][0] >>v[i][1];
		sort(v.begin() + 1, v.end(), [&](auto a, auto b)
		{
			return a[1] > b[1];
		});

		priority_queue<int, vector<int>, greater<>> q; i64 sum = 0;
		int j = 1; i64 res = -1;
		vector<i64> f(n + 1);
		for(int i = n; i >= 0; i --)
		{
			while(j <= n && v[j][1] >= i)
			{
				q.emplace(v[j][0]);
				sum += v[j][0];
				j ++;
			}
			while(q.size() > i + 1)
			{
				sum -= q.top();
				q.pop();
			}
			if(q.size() == i + 1) res = max(res, sum);

			if(i == 0) f[0] = 0LL;
			else if(q.size() <= i) f[i] = sum;
			else f[i] = sum - q.top();
		}

		for(int y = 1; y <= n; y ++)
			f[y] = max(f[y], f[y - 1]);

		vector<i64> ans(m + 1);
		for(int i = 1; i <= m; i ++)
		{
			int x, y; cin >>x >>y;
			ans[i] = max(res, (i64)x + f[y]);
		}
		tell(1, ans);
	}
	return 0;
}
