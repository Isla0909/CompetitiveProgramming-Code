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
		int n, m, c; cin >>n >>m >>c;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 2; i <= n; i ++) cin >>a[i] >>b[i];

		vector<vector<int>> adj(n + 1);
		while(m --)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		queue<int> q;
		vector<int> st(n + 1);
		q.push(1); st[1] = 1;
		while(q.size())
		{
			auto u = q.front(); q.pop();
			for(auto v : adj[u])
			{
				if(!st[v])
				{
					st[v] = 1;
					q.push(v);
				}
			}
		}

		vector<int> f(c + 1);
		for(int i = 1; i <= n; i ++)
		{
			if(!st[i]) continue;
			for(int j = c; j >= a[i]; j --)
				f[j] = max(f[j], f[j - a[i]] + b[i]);
		}
		cout <<f[c] <<endl;
	}
	return 0;
}
