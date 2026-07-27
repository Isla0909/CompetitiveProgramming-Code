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
#define ff first
#define se second
#define endl '\n'
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector <map <int, vector<int>>> adj(n + 1);
		while(m --)
		{
			int a, b, c; cin >>a >>b >>c;
			adj[a][c].push_back(b);
			adj[b][c].push_back(a);
		}

		int s, e; cin >>s >>e;
		map <pii, int> dis;
		deque <tuple<int, int, int>> q;
		q.emplace_back(0, s, 0);
		while(q.size())
		{
			auto [d, x, a] = q.front(); q.pop_front();

			if(dis.count({x, a})) continue;
			dis[{x, a}] = d;

			if(a)
			{
				q.emplace_front(d, x, 0);
				for(auto y : adj[x][a])
					q.emplace_front(d, y, a);
			}
			else
			{
				for(auto &[a, _] : adj[x])
					q.emplace_back(d + 1, x, a);
			}
		}
		cout <<dis[{e, 0}] <<endl;
	}
	return 0;
}