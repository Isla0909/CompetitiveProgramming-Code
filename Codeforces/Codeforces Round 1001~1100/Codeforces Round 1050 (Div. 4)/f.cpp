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
using i32 = unsigned;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> g(n);
		vector<pii> v(n);
		for(int i = 0; i < n; i ++)
		{
		    int m; cin >>m;
		    for(int j = 0; j < m; j ++)
		    {
		        int x; cin >>x;
		        g[i].push_back(x);
		    }
		    v[i].ff = m, v[i].se = i;
		}
		sort(v.begin(), v.end());
		int l = 0; vector<int> ans;
		while(l < n)
		{
		    int x = v[l].se;
		    for(int i = l + 1; i < n; i ++)
		    {
		        if(g[v[i].se] < g[x]) x = v[i].se;
		    }
		    for(int i = 0; i < g[x].size(); i ++)
		        ans.push_back(g[x][i]);
		    while(l < n && g[v[l].se].size() <= g[x].size()) l ++;
		    
		    vector<vector<int>> f(n);
		    for(int i = l; i < n; i ++)
		    {
		        for(int j = g[x].size(); j < g[v[i].se].size(); j ++)
		            f[v[i].se].push_back(g[v[i].se][j]);
		    }
		    g = f;
		}
		for(int i = 0; i < ans.size(); i ++)
		    cout <<ans[i] <<" \n"[i == ans.size() - 1];
	}
	return 0;
}