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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e4 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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
		unordered_map<string, unordered_map<string, int>> mp;
		int idx = 1;
		auto trans = [&](string s)
		{
			vector<int> res; int last = 0;
			for(int i = 0; i < s.size(); i ++)
			{
				if(s[i] == '/')
				{
					int len = i - 1 - last + 1;
					string pre = s.substr(0, i);
					string t = s.substr(last, len);
					last = i + 1;
					int c;
					if(mp[pre].count(t)) c = mp[pre][t];
					else
					{
						mp[pre][t] = idx ++;
						c = mp[pre][t];
					} 
					res.push_back(c);
				}
			}
			return res;
		};

		int n, m; cin >>n >>m;
		vector<int> root;
		vector<int> w(100000);
		vector<vector<int>> adj(100000);

		for(int i = 0; i < n; i ++)
		{
			string s; cin >>s;
			s += '/';
			auto v = trans(s);
			root.push_back(v[0]);
			for(auto x : v)
				w[x] = 1;
			for(int i = 1; i < v.size(); i ++)
			{
				int a = v[i - 1], b = v[i];
				adj[a].push_back(b);
			}
		}
		for(int i = 0; i < m; i ++)
		{
			string s; cin >>s;
			s += '/';
			auto v = trans(s);
			root.push_back(v[0]);

			for(int i = 1; i < v.size(); i ++)
			{
				int a = v[i - 1], b = v[i];
				adj[a].push_back(b);
			}
			//tell(0, v);
		}

		sort(root.begin(), root.end());
		root.erase(unique(root.begin(), root.end()), root.end());

		for(int i = 1; i < idx; i ++)
		{
			sort(adj[i].begin(), adj[i].end());
			adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
		}

		vector<int> siz(N), val(N);

		auto dfs = [&](this auto &&self, int u) -> void
		{
			siz[u] = 1, val[u] = w[u];
			for(auto v : adj[u])
			{
				self(v);
				siz[u] += siz[v];
				val[u] += val[v];
			}
		};

		auto calc = [&](this auto &&self, int u) -> i32
		{
			if(siz[u] == val[u]) return 1;
			int res = 0;
			for(auto v : adj[u])
			{
				res += self(v);
			}
			//cout <<u <<" " <<res <<endl;
			return res;
		};


		int ans = 0;
		for(int i = 0; i < root.size(); i ++)
		{
			int u = root[i];
			dfs(u);
			ans += calc(u);
		}

		// for(int i = 1; i < idx; i ++)
		// 	cout <<i <<" " <<siz[i] <<" " <<val[i] <<endl;

		cout <<ans <<endl;
	}

	return 0;
}