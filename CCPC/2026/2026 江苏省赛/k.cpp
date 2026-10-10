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

	int T; cin >>T;
	while(T --)
	{
		int n, a; cin >>n >>a;
		vector<int> v(n + 1);
		for(int i = 1; i <= n; i ++) cin >>v[i];

		int m; cin >>m;
		vector<array<int, 2>> query(m + 1);
		for(int i = 1; i <= m; i ++)
		{
			int b; cin >>b;
			query[i] = {i, b};
		}

		sort(query.begin() + 1, query.end(), [&](auto &a, auto &b)
		{
			return a[1] < b[1];
		});

		vector<i64> ans(m + 1), diff(m + 2);
		vector<int> b(m + 1);
		for(int i = 1; i <= m; i ++)
			b[i] = query[i][1];

		i64 res = 0;
		priority_queue<int, vector<int>, greater<>> q;
		for(int i = 1; i <= n; i ++)
		{
			if(v[i] <= a)
			{
				res += v[n] - v[i];
				q.emplace(v[i]);
			}
			else if(q.size() && q.top() < v[i])
			{
				int p = q.top(); q.pop();
				q.emplace(v[i]);

				//p < b <= v[i];
				int l = upper_bound(b.begin() + 1, b.end(), p) - b.begin();
				int r = upper_bound(b.begin() + 1, b.end(), v[i]) - b.begin();

				i64 w = v[i] - v[n];
				diff[l] += w, diff[r] -= w;
			}
		}

		for(int i = 1; i <= m; i ++)
		{
			diff[i] += diff[i - 1];
			ans[query[i][0]] = res + diff[i];
		}

		for(int i = 1; i <= m; i ++)
			cout <<ans[i] <<" \n"[i == m];
	}
	return 0;
}
