#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

struct cxy
{
	int u, v;
	i64 w;
	cxy() {}
	cxy(int u, int v, i64 w) : u(u), v(v), w(w) {}
};

int p[N], siz[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector a(n + 1, vector<i64>(n + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			cin >>a[i][j];
	vector pre(n + 1, vector<i64>(n + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];

	auto get = [&](int x1, int y1, int x2, int y2) -> i64
	{
		return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
	};
	
	vector g(n + 1, vector<i64>(n + 1));
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			g[i][j] = g[j][i] = get(1, i, i, j - 1) + get(i + 1, j, j, n);

	vector<cxy> edges;
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			edges.emplace_back(i, j, get(1, i, i, j - 1) + get(i + 1, j, j, n));
	
	sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
	{
		return a.w < b.w;
	});

	i64 ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i += 2)
		ans1 += g[i][i + 1];

	ans2 = g[1][n];
	for(int i = 2; i <= n - 1; i += 2)
		ans2 += g[i][i + 1];
	cout <<min(ans1, ans2) <<endl;

	return 0;
}