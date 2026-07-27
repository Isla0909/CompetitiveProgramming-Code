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
		
		int n, s, x; cin >>n >>s >>x;
		vector<int> a(n + 1); vector<ll> pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
		}

		vector st(n + 1, vector<int>(20, 0));
		for(int j = 0; j <= 19; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][0] = a[i];
				else st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
		auto query = [&](int l, int r) -> int
		{
			if(l > r) swap(l, r);
			int k = __lg(r - l + 1);
			return max(st[l][k], st[r - (1 << k) + 1][k]);
		};

		
		auto get = [&](int x) -> int 
		{
			map<int, int> mp; mp[0] = 1;
			int ans = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] > x) mp.clear();

				if(mp.count(pre[i] - s))
					ans += mp[pre[i] - s];
				mp[pre[i]] ++;
			}
			return ans;
		};
		cout <<get(x) - get(x - 1) <<endl;
	}
	return 0;
}