#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using i64 = long long;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

struct cxy
{
	int u, v;
	i64 w;
	cxy(int u, int v, i64 w) : u(u), v(v), w(w) {}
};

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

int p[1000005];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(5000000);

	vector<int> last(5000001, -1);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		

		vector<int> a(n + 1);
		vector<vector<int>> vec(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			int x = a[i];
			while(x > 1)
			{
				int p = minp[x];
				vec[i].push_back(p);
				while(x % p == 0) x /= p;
			}
			assert(x <= 1);
		}
		
		if(n == 1)
		{
			cout <<0 <<endl;
			continue;
		}

		vector<cxy> edges;
		for(int i = 1; i <= n; i ++)
		{
			for(auto p : vec[i])
			{
				if(last[p] != -1)
				{
					int u = last[p], v = i;
					assert(v > u);
					i64 w = 1LL * p * (v - u);
					edges.emplace_back(u, v, w);
				}
				last[p] = i;
			}
			if(vec[i].size() <= 1) continue;
			sort(vec[i].begin(), vec[i].end());
			vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
		}
		sort(edges.begin(), edges.end(), [&](auto a, auto b)
		{
			return a.w < b.w;
		});


		for(int i = 1; i <= n; i ++)
			p[i] = i;

		int cnt = n;
		i64 ans = -1;
		for(auto [u, v, w] : edges)
		{
			//cout <<u <<" " <<v <<" " <<w <<endl;

			int pu = find(u), pv = find(v);
			if(pu == pv) continue;

			ans = w;
			p[pu] = pv;
			cnt --;
		}

		if(cnt == 1) cout <<ans <<endl;
		else cout <<-1 <<endl;

		for(int i = 1; i <= n; i ++)
			for(auto p : vec[i])
				last[p] = -1;
	}
	return 0;
}