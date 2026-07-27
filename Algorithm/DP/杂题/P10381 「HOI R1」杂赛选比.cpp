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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n;
int h[N], nex[M], val[M], w[M]; int idx;
int dist[N]; bool st[N];
int a[N], pre[N];


void add(int a, int b, int c)
{
	nex[idx] = h[a], val[idx] = b, w[idx] = c, h[a] = idx ++;
}

void spfa()
{
	memset(dist, 0, sizeof dist), memset(st, 0, sizeof st);
	queue <int> q; dist[1] = a[1];
	q.push(1); st[1] = 1;
	while(q.size())
	{
		auto t = q.front(); q.pop(); st[t] = 0;
		for(int i = h[t]; ~ i; i = nex[i])
		{
			int j = val[i];
			if(dist[j] < dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					q.push(j);
					st[j] = 1;
				}
			}
		}
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		memset(h, -1, sizeof h); idx = 0;

		cin >>n;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
		}

		for(int i = 2; i <= n; i ++)
			add(i, i - 1, -a[i]);
		for(int i = 1; i <= n; i ++)
		{
			int j = min(n, i + a[i]);
			add(i, j, pre[j] - pre[i] - a[i]);
		}

		spfa();
		int ans = 0;
		for(int i = 1; i <= n; i ++)
			ans = max(ans, dist[i]);
		cout <<ans <<endl;
	}
	return 0;
}