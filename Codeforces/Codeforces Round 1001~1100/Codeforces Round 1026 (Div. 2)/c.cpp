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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> d(n + 1), pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>d[i];
			pre[i] = pre[i - 1] + (d[i] == -1);
		}

		vector<pii> v(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >>v[i].ff >>v[i].se;

		vector<int> low(n + 1), lim(n + 1, INF);
		int x = 0; bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(d[i] != -1) x += d[i];

			low[i] = max(low[i - 1], v[i].ff - x);
			lim[i] = min(lim[i - 1] + (d[i] == -1), v[i].se - x);
			if(lim[i] < 0 || low[i] > lim[i]) f = 0;
			if(low[i] > 0 && pre[i] < low[i]) f = 0;

			//cout <<low[i] <<" " <<lim[i] <<endl;
		}
		if(!f) cout <<-1 <<endl;
		else
		{
			int now = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(lim[i] == now && d[i] == -1) d[i] = 0;
				else
				{
					if(now < low[i])
					{
						int x = low[i] - low[i - 1];
						int j = i;
						while(x)
						{
							while(d[j] != -1) j --;
							d[j] = 1, now ++;
							x --;
						}
					}
				}
			}

			for(int i = 1; i <= n; i ++)
			{
				if(d[i] != -1) cout <<d[i] <<" ";
				else cout <<0 <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}