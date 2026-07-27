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

//能移动: 1.上面有a[i]个  2.目的地没有小的 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1); bool f = 1;
		for(int i = 1; i <= n; i ++) 
		{
			cin >>a[i];
			if(a[i] > i - 1) f = 0;
		}

		if(!f)
		{
			cout <<"NO" <<endl;
			continue;
		}

		cout <<"YES" <<endl;
		vector<array<int, 3>> ans;
		vector<int> now(n + 1, 1), to(n + 1, 3);
		auto dfs = [&](this auto &&self, int u, vector<int> &to) -> void
		{
			if(u == 0) return ;

			if(to[u] == now[u])
			{
				self(u - 1, to);
				return ;
			}

			int x = now[u], y = to[u], z = 6 - x - y;
			// tell(1, now);
			// tell(1, to);
			// cout <<u <<" " <<x <<" " <<y <<" " <<z <<endl;
			//x -> y
			vector<int> v(n + 1);
			for(int i = 1; i <= u - 1; i ++)
			{
				//1 - a[u]
				if(i <= a[u]) v[i] = x;
				else v[i] = z; 
			}
			self(u - 1, v);

			if(now[u] != y)
			{
				ans.push_back({u, x, y});
				now[u] = y;
			}

			self(u - 1, to);
		};
		dfs(n, to);
		cout <<ans.size() <<endl;
		for(auto [x, y, z] : ans)
			cout <<x <<" " <<y <<" " <<z <<endl;
	}
	return 0;
}
