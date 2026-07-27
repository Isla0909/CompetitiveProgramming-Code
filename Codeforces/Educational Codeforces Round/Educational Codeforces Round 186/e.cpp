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
		int n, m; i64 k; cin >>n >>m >>k;
		vector<int> a(m);
		for(int i = 0; i < m; i ++) cin >>a[i];

		vector<array<int, 3>> v(n);
		for(int i = 0; i < n; i ++)
		{
			int x, y, z; cin >>x >>y >>z;
			k -= y, z -= y;
			v[i] = {x, z, i};
		}

		sort(a.begin(), a.end());

		sort(v.begin(), v.end(), [&](auto &a, auto &b)
		{
			return a[0] < b[0];
		});

		priority_queue<pii> q;
		vector<int> used(n);

		int ans = 0, j = -1;
		for(int i = 0; i < m; i ++)
		{
			int x = a[i];
			while(j + 1 < n && v[j + 1][0] <= x)
			{
				j ++;
				q.emplace(v[j][1], v[j][2]);
			}

			if(q.size())
			{
				auto [cost, id] = q.top(); q.pop();
				used[id] = 1;
				ans ++;
			}
		}
		vector<int> b;
		for(auto [x, c, id] : v)
		{
			if(!used[id])
				b.push_back(c);
		}
		sort(b.begin(), b.end());
		for(auto x : b)
		{
			if(k >= x)
			{
				k -= x;
				ans ++;
			}
			else break;
		}
		cout <<ans <<endl;
	}
	return 0;
}
