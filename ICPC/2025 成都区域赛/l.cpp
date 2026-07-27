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
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> siz(n + 1), in(n + 1), seq(n + 1); int cur = 1;
		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			siz[u] = 1, in[u] = cur ++;
			seq[in[u]] = u;

			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
				siz[u] += siz[v];
			}
		};

		dfs(1, -1);

		int len = sqrt(n);
		vector<int> bel(n + 1);
		for(int i = 1; i <= n; i ++)
			bel[i] = (i - 1) / len + 1;

		vector<array<int, 3>> query(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int l = in[i], r = in[i] + siz[i] - 1;
			query[i] = {i, l, r};
		}
		sort(query.begin() + 1, query.end(), [&](auto a, auto b)
		{
			if(bel[a[1]] != bel[b[1]]) return bel[a[1]] < bel[b[1]];
			if(bel[a[1]] & 1) return a[2] < b[2];
			return a[2] > b[2];
		});

		vector<int> cnt(n + 1), ans(n + 1);
		int l = 1, r = 0, s0 = 0, s1 = 0;

		auto add = [&](int u) -> void
		{
			int x = a[u], y = b[u];
			if(x == 0) s0 ++;
			else
			{
				s1 -= abs(cnt[x]);
				cnt[x] ++;
				s1 += abs(cnt[x]);
			}
			if(y == 0) s0 ++;
			else
			{
				s1 -= abs(cnt[y]);
				cnt[y] --;
				s1 += abs(cnt[y]);
			}
		};

		auto del = [&](int u) -> void
		{
			int x = a[u], y = b[u];
			if(x == 0) s0 --;
			else
			{
				s1 -= abs(cnt[x]);
				cnt[x] --;
				s1 += abs(cnt[x]);
			}
			if(y == 0) s0 --;
			else
			{
				s1 -= abs(cnt[y]);
				cnt[y] ++;
				s1 += abs(cnt[y]);
			}
		};

		for(int i = 1; i <= n; i ++)
		{
			auto [id, ql, qr] = query[i];
			while(l > ql) add(seq[-- l]);
			while(r < qr) add(seq[++ r]);
			while(l < ql) del(seq[l ++]);
			while(r > qr) del(seq[r --]);
			ans[id] = (s0 >= s1);
		}
		for(int i = 1; i <= n; i ++)
			cout <<ans[i];
		cout <<endl;
	}
	return 0;
}
