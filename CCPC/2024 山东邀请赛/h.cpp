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

struct hseg
{
	int x, l, r;
	hseg() {}
	hseg(int x, int l, int r) : x(x), l(l), r(r) {}
};

struct vseg
{
	int y, u, d;
	vseg() {}
	vseg(int y, int u, int d) : y(y), u(u), d(d) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		map<int, vector<pii>> row, col;

		int n; cin >>n;
		for(int i = 0; i < n; i ++)
		{
			int x, y; cin >>x >>y;
			row[x].emplace_back(y, 1);
			col[y].emplace_back(x, 1);
		}

		int m; cin >>m;
		for(int i = 0; i < m; i ++)
		{
			int x, y; cin >>x >>y;
			row[x].emplace_back(y, 0);
			col[y].emplace_back(x, 0);
		}

		vector<hseg> h;
		vector<vseg> v;
		bool ok = true;

		for(auto &[x, a] : row)
		{
			sort(a.begin(), a.end());

			for(int i = 1; i < a.size(); i ++)
			{
				if(a[i - 1].se && a[i].se)
				{
					if(a[i].ff == a[i - 1].ff + 1) ok = false;
					else h.emplace_back(x, a[i - 1].ff, a[i].ff);
				}
			}
		}
		for(auto &[y, a] : col)
		{
			sort(a.begin(), a.end());

			for(int i = 1; i < a.size(); i ++)
			{
				if(a[i - 1].se && a[i].se)
				{
					if(a[i].ff == a[i - 1].ff + 1) ok = false;
					else v.emplace_back(y, a[i - 1].ff, a[i].ff);
				}
			}
		}

		if(!ok) 
		{
			cout <<-1 <<endl;
			continue;
		}

		int n1 = h.size(), n2 = v.size();
		vector<vector<int>> adj(n1);
		for(int i = 0; i < n1; i ++)
		{
			for(int j = 0; j < n2; j ++)
			{
				if(h[i].l < v[j].y && v[j].y < h[i].r && v[j].u < h[i].x && h[i].x < v[j].d)
					adj[i].push_back(j);
			}
		}

		vector<int> match(n2, -1), vis(n2);
		auto find = [&](this auto &&self, int u) -> bool
		{
			for(auto x : adj[u])
			{
				if(vis[x]) continue;
				vis[x] = 1;

				if(match[x] == -1 || self(match[x]))
				{
					match[x] = u;
					return true;
				}
			}
			return false;
		};

		int res = 0;
		for(int i = 0; i < n1; i ++)
		{
			fill(vis.begin(), vis.end(), 0);
			if(find(i)) res ++;
		}

		vector<int> useh(n1), usev(n2);
		vector<pii> ans;
		for(int j = 0; j < n2; j ++)
		{
			if(match[j] == -1) continue;

			int i = match[j];
			useh[i] = usev[j] = 1;
			ans.emplace_back(h[i].x, v[j].y);
		}

		for(int i = 0; i < n1; i ++)
			if(!useh[i]) ans.emplace_back(h[i].x, h[i].l + 1);
		for(int j = 0; j < n2; j ++)
			if(!usev[j]) ans.emplace_back(v[j].u + 1, v[j].y);

		cout <<ans.size() <<endl;
		for(auto [x, y] : ans)
			cout <<x <<" " <<y <<endl;
	}
	return 0;
}
