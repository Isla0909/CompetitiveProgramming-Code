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

	freopen("skating.in", "r", stdin);
	freopen("skating.out", "w", stdout);
	
	int h, w, n; cin >>h >>w >>n;
	int sx, sy, ex, ey; cin >>sx >>sy >>ex >>ey;

	vector<pii> blocks(n);
	vector<pii> v;
	v.emplace_back(sx, sy), v.emplace_back(ex, ey);

	for(int i = 0; i < n; i ++)
	{
		int x, y; cin >>x >>y;
		blocks[i] = {x, y};

		if(x > 1) v.emplace_back(x - 1, y);
		if(x < h) v.emplace_back(x + 1, y);
		if(y > 1) v.emplace_back(x, y - 1);
		if(y < w) v.emplace_back(x, y + 1);
	}

	vector<pii> row = blocks, col;
	sort(row.begin(), row.end());

	for(auto [x, y] : blocks)
		col.emplace_back(y, x);
	sort(col.begin(), col.end());

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<pii> nv;
	for(auto pos : v)
	{
		if(!binary_search(row.begin(), row.end(), pos))
			nv.emplace_back(pos);
	}
	v.swap(nv);

	auto get = [&](int x, int y) -> int
	{
		pii pos = {x, y};
		auto it = lower_bound(v.begin(), v.end(), pos);

		if(it == v.end() || *it != pos) return -1;
		return it - v.begin();
	};

	int s = get(sx, sy), e = get(ex, ey);
	if(s == -1 || e == -1)
	{
		cout <<-1 <<endl;
		return 0;
	}

	int m = v.size();
	vector<int> dist(m, -1);
	queue<int> q;
	dist[s] = 0; q.emplace(s);

	auto add = [&](int x, int y, int d) -> void
	{
		int id = get(x, y);
		if(id == -1 || dist[id] != -1) return ;
		
		dist[id] = d;
		q.emplace(id);
	};

	while(q.size())
	{
		auto t = q.front(); q.pop();

		if(t == e) break;

		auto [x, y] = v[t];
		auto itr = lower_bound(row.begin(), row.end(), pii{x, y});
		if(itr != row.end() && itr->ff == x)
		{
			int ny = itr->se - 1;
			add(x, ny, dist[t] + 1);
		}

		if(itr != row.begin())
		{
			auto it = prev(itr);
			if(it->ff == x)
			{
				int ny = it->se + 1;
				add(x, ny, dist[t] + 1);
			}
		}

		auto itd = lower_bound(col.begin(), col.end(), pii{y, x});
		if(itd != col.end() && itd->ff == y)
		{
			int nx = itd->se - 1;
			add(nx, y, dist[t] + 1);
		}

		if(itd != col.begin())
		{
			auto it = prev(itd);
			if(it->ff == y)
			{
				int nx = it->se + 1;
				add(nx, y, dist[t] + 1);
			}
		} 
	}
	cout <<dist[e] <<endl;
	return 0;
}
