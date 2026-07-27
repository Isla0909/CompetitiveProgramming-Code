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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector <vector<int>> adj(n + 1), back(n + 1);
		for(int i = 1; i < n; i ++)
		{
			adj[i].push_back(i + 1);
			back[i + 1].push_back(i);
		}
		while(m --)
		{
			int a, b; cin >>a >>b;
			adj[a].push_back(b);
			back[b].push_back(a);
		}
		vector <int> d(n + 1, INF), cnt(n + 1, 0);
		vector <bool> st(n + 1, 0);
		vector <bool> ha(n + 1, 0);

		auto spfa = [&]() -> void
		{
			d[1] = 0, cnt[1] = 1;
			queue <int> q;
			q.push(1);
			while(q.size())
			{
				auto t = q.front(); q.pop();
				for(auto j : adj[t])
				{
					if(d[j] > d[t] + 1)
					{
						d[j] = d[t] + 1;
						cnt[j] = cnt[t];
						q.push(j);
					}
					else if(d[j] == d[t] + 1)
					{
						//if(j == 8) cout <<t <<endl;
						cnt[j] += cnt[t];
					}
				}
			}
		};
		// auto calc = [&]() -> void
		// {
		// 	queue <int> q; q.push(n);
		// 	st[n] = 1;
		// 	while(q.size())
		// 	{
		// 		auto t = q.front(); q.pop();
		// 		for(auto j : back[t])
		// 		{
		// 			if(d[j] == d[t] - 1)
		// 			{
		// 				q.push(j);
		// 				if(cnt[t] == 1) st[j] = 1;
		// 			}
		// 		}
		// 	}
		// };

		spfa(); //calc();

		vector <int> diff(n + 1, 0);
		for(int i = 1; i <= n; i ++)
		{
			for(auto j : adj[i])
			{
				int l = i + 1;
				int r = j - d[i];
				if(l < r)
				{
					diff[l] ++;
					diff[r - 1] --;
				}
			}
		}
		for(int i = 2; i <= n; i ++)
			diff[i] += diff[i - 1];
		for(int i = 1; i < n; i ++)
			cout <<(diff[i] == 0);
		cout <<endl;
	}
	return 0;
}