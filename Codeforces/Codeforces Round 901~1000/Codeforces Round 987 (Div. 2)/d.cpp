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
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
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
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<pii> pre_max(n + 1), suf_min(n + 1);
		pre_max[1] = {a[1], 1};
		for(int i = 2; i <= n; i ++)
		{
			if(a[i] > pre_max[i - 1].ff) pre_max[i] = {a[i], i};
			else pre_max[i] = pre_max[i - 1];
		}
		suf_min[n] = {a[n], n};
		for(int i = n - 1; i >= 1; i --)
		{
			if(a[i] < suf_min[i + 1].ff) suf_min[i] = {a[i], i};
			else suf_min[i] = suf_min[i + 1];
		}

		vector<int> p(n + 1);
		for(int i = 1; i <= n; i ++) p[i] = i;

		function <int(int)> find;
		find = [&](int x)
		{
			if(x != p[x]) p[x] = find(p[x]);
			return p[x];
		};

		for(int i = 1; i <= n; i ++)
		{
			if(i - 1 >= 1 && pre_max[i - 1].ff > a[i]) p[i] = pre_max[i - 1].se;
			if(i + 1 <= n && suf_min[i + 1].ff < a[i])
			{
				int l = 0, r = n + 1;
				while(l + 1 != r)
				{
					int mid = l + r >> 1;
					if(suf_min[mid].ff >= a[i]) r = mid;
					else l = mid;
				}
				if(i != pre_max[l].se) p[i] = suf_min[l].se;
			}
			//cout <<p[i] <<" ";
		}

		for(int i = 1; i <= n; i ++)
			cout <<a[find(i)] <<" \n"[i == n];
	}
	return 0;
}