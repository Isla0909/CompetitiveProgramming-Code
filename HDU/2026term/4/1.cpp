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

int dx[4] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector g(n + 1, vector<int>(m + 1));
		vector<int> st(n + m);
		vector<vector<int>> adj(n + m + 1);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				int x; cin >>x;
				g[i][j] = x;
				adj[i + j].push_back(x);
			}
		for(int i = 2; i <= n + m; i ++)
		{
			int sm = *min_element(adj[i].begin(), adj[i].end());
			int M = *max_element(adj[i].begin(), adj[i].end());
			if(sm == M && sm < n + m) st[sm] = 1;
		}
		int s = 0;
		for(int i = 0; i < n + m; i ++)
			if(!st[i])
			{
				s = i;
				break;
			}

		for(int i = s; i < n + m; i ++)
		{
			vector vis(n + 1, vector<int>(m + 1));
			queue<pii> q;
			if(g[1][1] != i) q.emplace(1, 1), vis[1][1] = 1;
 			while(q.size())
			{
				auto [x, y] = q.front(); q.pop();
				for(int u = 0; u < 4; u ++)
				{
					int a = x + dx[u], b = y + dy[u];
					if(a >= 1 && a <= n && b >= 1 && b <= m && !vis[a][b] && g[a][b] != i)
					{
						vis[a][b] = 1;
						q.emplace(a, b);
					}
				}
			}
			int f = (vis[n][m] == 1);
			vector<int> v(i);
			for(int x = 1; x <= n; x ++)
				for(int y = 1; y <= m; y ++)
					if(vis[x][y] && g[x][y] < i)
						v[g[x][y]] = 1;
			for(int j = 0; j < i; j ++)
				if(!v[j]) 
				{
					f = 0;
					break;
				}
			if(f)
			{
				cout <<i <<endl;
				break;
			}
		}
	}
	return 0;
}
