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
		int n, m; cin >>n >>m;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> x(m + 1), t(m + 1);
		vector<vector<int>> pos(n + 1);
		for(int i = 1; i <= m; i ++)
		{
			cin >>x[i] >>t[i];
			pos[t[i]].push_back(i);
		}

		vector<i64> last(n + 1, inf);
		vector<i64> nex(m + 1, inf);

		for(int i = 1; i <= n; i ++)
		{
			auto &v = pos[i];
			if(!v.size()) continue;
			last[i] = x[v[0]];
			for(int j = 0; j + 1 < v.size(); j ++)
				nex[v[j]] = x[v[j + 1]];
		}

		priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> q;
		for(int i = 1; i <= n; i ++)
			q.emplace(last[i], a[i]);

		i64 pre = 0; bool f = 1;
		for(int i = 1; i <= m; i ++)
		{
			i64 need = x[i] - pre;
			i64 move = 0;

			while(need > 0)
			{
				if(!q.size())
				{
					cout <<pre + move <<endl;
					f = 0;
					break;
				}
				auto [death, remain] = q.top(); q.pop();
				i64 use = min(remain, need);
				need -= use;
				move += use;
				remain -= use;
				if(remain) q.emplace(death, remain);
			}

			if(!f) break;
			pre = x[i];

			while(q.size() && q.top().ff == x[i])
				q.pop();

			q.emplace(nex[i], a[t[i]]);
		} 
		if(f)
		{
			i64 ans = pre;
			while(q.size())
			{
				auto [_, remain] = q.top(); q.pop();
				ans += remain;
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}
