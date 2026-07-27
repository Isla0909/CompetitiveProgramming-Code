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
#define int long long
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

struct cxy
{
	int x;
	int d;
	int f;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<pii> adj[n];
		while(m --)
		{
			int a, b, c; cin >>a >>b >>c;
			a --, b --;
			adj[a].emplace_back(b, c);
			adj[b].emplace_back(a, c);
		}
		vector<int> s(n);
		for(int i = 0; i < n; i ++) cin >>s[i];

		vector<int> dis(n * n , -1LL);
		priority_queue<pii, vector<pii>, greater<pii>> q;
		q.emplace(0, 0);
		while(q.size())
		{
			auto [d, x] = q.top(); q.pop();

			if(dis[x] != -1) continue;
			dis[x] = d;

			int c = x / n, b = x % n;
			if(c == n - 1)
			{
				cout <<d <<endl;
				break;
			}
			q.emplace(d, c * n + c);

			for(auto [v, w] : adj[c])
				q.emplace(d + s[b] * w, v * n + b);
		}
	}
	return 0;
}