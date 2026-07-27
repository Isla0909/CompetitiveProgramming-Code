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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<pii> adj[n + 1];
		vector<int> w(n + 1), din(n + 1);
		for(int i = 1; i <= n; i ++) cin >>w[i];

		while(m --)
		{
			int a, b, c; cin >>a >>b >>c;
			adj[a].push_back({b, c});
			din[b] ++;
		}

		auto check = [&](int x) -> bool
		{
			vector<int> d = din;
			vector<int> now(n + 1, -1);
			now[1] = min(w[1], x);
			queue<int> q;
			for(int i = 1; i <= n; i ++)
				if(!d[i]) q.push(i);
			while(q.size())
			{
				auto t = q.front(); q.pop();
				//cout <<t <<" " <<now[t] <<endl;
				for(auto [v, need] : adj[t])
				{
					if(now[t] >= need) now[v] = min(x, max(now[t] + w[v], now[v]));

					d[v] --;
					if(!d[v]) q.push(v);
				}
			}
			return now[n] != -1;
		};

		int l = 0, r = 1e9 + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			//cout <<l <<" l and r " <<r <<" mid " <<mid <<endl;
			if(check(mid)) r = mid;
			else l = mid;
		}
		if(r == 1e9 + 1) cout <<-1 <<endl;
		else cout <<r <<endl;
	}
	return 0;
}