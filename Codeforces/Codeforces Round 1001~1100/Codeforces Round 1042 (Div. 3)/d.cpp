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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> adj[n + 1], d(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v; cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);

			d[u] ++, d[v] ++;
		}

		vector<int> cnt(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int c = 0;
			for(auto v : adj[i])
			{
				if(d[v] == 1) c ++;
			}
			cnt[i] = c;
		}

		int s = 0, mmax = 0, r = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(adj[i].size() == 1) s ++;

			if(cnt[i] > mmax)
			{
				mmax = cnt[i];
				r = i;
			}
		}

		if(adj[r].size() == 1)
		{
			if(n == 2) cout <<0 <<endl;
			else cout <<1 <<endl;
		}
		else cout <<s - mmax <<endl;
	}
	return 0;
}