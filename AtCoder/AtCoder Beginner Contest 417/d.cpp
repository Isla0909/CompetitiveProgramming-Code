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
#define int long long
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

	freopen("in.txt", "r", stdin);
	freopen("AC.txt", "w", stdout);

	int n; cin >>n;
	vector<int> p(n + 1), a(n + 1), b(n + 1);
	vector<int> prea(n + 1), preb(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>p[i] >>a[i] >>b[i];
		preb[i] = preb[i - 1] + b[i];
	}

	int m; cin >>m;
	map<int, int> mp;
	while(m --)
	{
		int x; cin >>x;
		int t = x;
		if(!mp[t])
		{
			cout <<mp[t] <<endl;
			continue;
		}
		int now = 0;
		while(now < n)
		{
			while(x >= 500)
			{
				int c = x / 500;
				c = min(c, n - now);
				x -= preb[now + c] - preb[now];
				now = now + c;
				if(now == n) break;
			}
			for(int i = now + 1; i <= n; i ++)
			{
				if(x <= p[i]) x += a[i];
				else x -= min(x, b[i]);
				now = i;
			}
		}
		mp[t] = x;
		cout <<x <<endl;
	}

	return 0;
}