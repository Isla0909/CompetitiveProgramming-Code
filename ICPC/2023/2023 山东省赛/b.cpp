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

	int g; cin >>g;
	vector<array<int, 2>> a(g);
	for(int i = 0; i < g; i ++)
		cin >>a[i][0] >>a[i][1];

	int n; cin >>n;
	map<int, priority_queue<pii, vector<pii>, greater<pii>> > need;
	vector<int> deg(n);
	vector<vector<array<int, 2>>> vec(n);
	for(int i = 0; i < n; i ++)
	{
		cin >>deg[i];
		for(int j = 0; j < deg[i]; j ++)
		{
			int id, c; cin >>id >>c;
			need[id].emplace(c, i);
		}

		int k; cin >>k;
		vec[i].resize(k);
		for(int j = 0; j < k; j ++)
			cin >>vec[i][j][0] >>vec[i][j][1];
	}
	queue<int> q;
	map<int, i64> cnt;
	auto add = [&](int id, int delta) -> void
	{
		i64 &v = cnt[id];
		v += delta;

		auto &pq = need[id];
		while(pq.size())
		{
			auto [c, task] = pq.top();
			if(c > v) break;
			
			pq.pop();
			deg[task] --;
			if(!deg[task]) q.emplace(task);
		}
	};

	for(int i = 0; i < n; i ++)
		if(!deg[i]) q.emplace(i);

	for(auto [id, c] : a)
		add(id, c);

	int ans = 0;
	while(q.size())
	{
		auto t = q.front(); q.pop();
		ans ++;
		for(auto [id, delta] : vec[t])
			add(id, delta);
	}
	cout <<ans <<endl;
	return 0;
}
