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

void tell(int l, vector<i64> &v)
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), d(n + 1), l(n + 1), r(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>d[i];

		for(int i = 1; i <= n; i ++)
		{
			l[i] = i - 1;
			r[i] = i + 1;
		}
		l[1] = r[n] = -1;

		vector<int> v;
		for(int i = 1; i <= n; i ++)
			v.push_back(i);

		vector<int> vis(n + 1, -1);
		for(int i = 1; i <= n; i ++)
		{
			vector<int> die;
			for(auto x : v)
			{
				int sum = 0;

				if(l[x] != -1) sum += a[l[x]];
				if(r[x] != -1) sum += a[r[x]];

				if(sum > d[x]) die.push_back(x);
			}
			v.clear();
			cout <<die.size() <<" \n"[i == n];

			for(auto x : die)
				vis[x] = i;

			for(auto x : die)
			{
				int pre = l[x];
				if(pre != -1)
				{
					r[pre] = r[x];

					if(vis[pre] < i)
					{
						v.push_back(pre);
						vis[pre] = i;
					}
				}

				int nxt = r[x];
				if(nxt != -1)
				{
					l[nxt] = l[x];

					if(vis[nxt] < i)
					{
						v.push_back(nxt);
						vis[nxt] = i;
					}
				}
			}
		}
	}	
	return 0;
}