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
#include <array>
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

int p[N], dist[N], siz[N];
int cnt[N][2];

int find(int x)
{
	if(x != p[x])
	{
		int fa = p[x];
		p[x] = find(p[x]);
		dist[x] ^= dist[fa];
	}
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	for(int i = 1; i <= n; i ++)
	{
		p[i] = i;
		siz[i] = 1;
		cnt[i][0] = 1;
		cnt[i][1] = 0;
		dist[i] = 0;
	}

	bool f = 1; int ans = 0;
	while(q --)
	{
		int a, b; cin >>a >>b;
		int pa = find(a), pb = find(b);

		if(!f) 
		{
			cout <<-1 <<endl;
			continue;
		}

		if(pa == pb)
		{
			if((dist[a] ^ dist[b]) != 1) f = 0;
		}
		else
		{
			ans -= min(cnt[pa][0], cnt[pa][1]);
			ans -= min(cnt[pb][0], cnt[pb][1]);

			int w = dist[a] ^ dist[b];
			p[pa] = pb; 
			siz[pb] += siz[pa];
			
			if(w == 0)
			{
				dist[pa] = 1;
				cnt[pb][1] += cnt[pa][0];
				cnt[pb][0] += cnt[pa][1];
			}
			else
			{
				dist[pa] = 0;
				cnt[pb][1] += cnt[pa][1];
				cnt[pb][0] += cnt[pa][0];
			}
			ans += min(cnt[pb][0], cnt[pb][1]);
		}
		if(f) cout <<ans <<endl;
		else cout <<-1 <<endl;
	}

	return 0;
}
