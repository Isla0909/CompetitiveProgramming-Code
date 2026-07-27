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
		int n, x; cin >>n >>x;
		string s; cin >>s;

		s = ' ' + s;
		vector<int> pre(n + 1);
		for(int i = 1; i <= n; i ++)
			pre[i] = pre[i - 1] + (s[i] == '#');


		int l = 0, r = n + 1;
		for(int i = x - 1; i >= 1; i --)
			if(s[i] == '#')
			{
				l = i;
				break;
			}
		for(int j = x + 1; j <= n; j ++)
			if(s[j] == '#')
			{
				r = j;
				break;
			}

		int ans = INF;
		//cout <<l <<" " <<r <<endl;
		if(x == 1 || x == n || pre[n] == 0) ans = 1;
		else if(pre[n] == n - 1) ans = min(ans, min(x, n - x + 1));
		else if(pre[x] == x - 1) ans = min(ans, min(x, n - x + 1));
		else if(r == x + 1) ans = min(ans, min(x, n - x + 1));
		else
		{
			int ll = x, rr = n - r + 1 + 1;
			int res1 = min(ll, rr);
			ll = l + 1, rr = n - x + 1;
			int res2 = min(ll, rr);
			ans = min(ans, max(res1, res2));
		}
		cout <<ans <<endl;
	}
	return 0;
}