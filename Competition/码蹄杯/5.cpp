#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int x, vector<int> &v)
{
	for(int i = 0; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<int> l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>l[i] >>r[i];

	vector<pii> adj[n + 1];
	while(m --)
	{
		int a, b, w; cin >>a >>b >>w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}

	function <void(int, int)> dfs = [&](int u, int fa) -> void
	{

	};

	return 0;
}