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
		int n, k; cin >>n >>k;
		vector<int> t(n + 1);
		for(int i = 1; i <= n; i ++) 
		{
			cin >>t[i];
			t[i] %= k;
		}

		i64 ans = 0;
		vector<bool> vis(n + 1);
		vis[1] = 1;
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;
		set<pii> s;

		auto add = [&](int x) -> void
		{
			int v = vis[x] ? (k - t[x]) % k : t[x];
			auto it = s.emplace(v, x).ff;
			auto l = prev(it == s.begin() ? s.end() : it);
			auto r = next(it);
			if(r == s.end()) r = s.begin();

			if(vis[x] != vis[r->se]) q.push({(t[x] + t[r->se]) % k, x, r->se});
			if(vis[x] != vis[l->se]) q.push({(t[x] + t[l->se]) % k, l->se, x});			
		};

		auto del = [&](int x)
		{
			int v = vis[x] ? (k - t[x]) % k : t[x];
			auto it = s.find({v, x});

			auto l = prev(it == s.begin() ? s.end() : it);
			auto r = next(it);
			if(r == s.end()) r = s.begin();

			if(vis[l->se] != vis[r->se]) q.push({(t[l->se] + t[r->se]) % k, l->se, r->se});
			s.erase(it);
		};
		
		for(int i = 1; i <= n; i ++)
			add(i);

		while(!q.empty())
		{
			auto [w, u, v] = q.top(); q.pop();

			if(vis[u] == vis[v]) continue;
			if(!vis[u]) swap(u, v);

			ans += w;
			del(v);
			vis[v] = 1;
			add(v);
		}
		cout <<ans <<endl;
	}
	return 0;
}
