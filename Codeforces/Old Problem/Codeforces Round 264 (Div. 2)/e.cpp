#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

vector<int> minp, primes;
void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V = 2e6;
	sieve(V);

	int n, q; cin >>n >>q;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++)
	{
		int u, v; cin >>u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ans(n + 1), dep(n + 1), last(V + 1, -1);

	auto rebuild = [&]() -> void
	{
		fill(last.begin(), last.end(), -1);

		auto dfs = [&](this auto &&self, int u, int fa) -> void
		{
			int div[8], pre[8]; int cnt = 0;
			int x = a[u];
			while(x > 1)
			{
				int p = minp[x];
				div[cnt ++] = p;
				while(x % p == 0) x /= p;
			}

			int res = -1;
			for(int i = 0; i < cnt; i ++)
			{
				int p = div[i], v = last[p];
				if(v != -1 && (res == -1 || dep[v] > dep[res]))
					res = v;
			}

			ans[u] = res;

			for(int i = 0; i < cnt; i ++)
			{
				int p = div[i];
				pre[i] = last[p];
				last[p] = u;
			}

			for(auto v : adj[u])
			{
				if(v == fa) continue;
				dep[v] = dep[u] + 1;
				self(v, u);
			}

			for(int i = 0; i < cnt; i ++)
			{
				int p = div[i];
				last[p] = pre[i];
			}
		};
		dep[1] = 0;
		dfs(1, 0);
	};

	rebuild();

	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int u; cin >>u;
			cout <<ans[u] <<endl;
		}
		else
		{
			int u, w; cin >>u >>w;
			a[u] = w;
			rebuild();
		}
	}
	return 0;
}
