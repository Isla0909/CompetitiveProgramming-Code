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

struct cxy
{
	int d, l, r;
	cxy(int d, int l, int r) : d(d), l(l), r(r) {}

	bool operator>(const cxy &T) const
	{
		return d > T.d;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		priority_queue<cxy, vector<cxy>, greater<>> q;
		map<pii, bool> mp;
		for(int i = 1; i < n; i ++)
			q.emplace(a[i + 1] - a[i], i, i + 1);
		

		vector<int> r(n + 2), l(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			r[i] = i + 1;
			l[i] = i - 1;
		}

		vector<int> ans;
		while(k --)
		{
			if(q.empty()) break;
			while(mp[{q.top().l, q.top().r}])
			{
				//cout <<q.top().l <<" " <<q.top().r <<endl;
				q.pop();
			}
			auto [_, i, hh] = q.top(); q.pop();

			//cout <<k <<" " <<i <<" " <<_ <<endl;
			ans.push_back(i);

			r[l[i]] = r[i];
			l[r[i]] = l[i];

			if(l[i] != 0 && r[i] <= n)
			{
				q.emplace(a[r[i]] - a[l[i]], l[i], r[i]);
				mp[{l[i], i}] = 1;
				//cout <<l[i] <<" l[i] and i " <<i <<endl;
			}
		}
		cout <<ans.size() <<endl;
		sort(ans.begin(), ans.end());
		tell(0, ans);
	}
	return 0;
}
