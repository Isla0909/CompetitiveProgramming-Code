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

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
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
		int n, k; cin >>n >>k;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		auto check = [&](int x) -> bool
		{
			bool st[x]; memset(st, 0, sizeof st);
			int cnt = 0; int now = 0;

			// if(!x)
			// {
			// 	int c = 0;
			// 	for(int i = 0; i < n; i ++)
			// 	{
			// 		if(!a[i]) c ++;
			// 	}
			// 	return c >= k;
			// }

			for(int i = 0; i < n; i ++)
			{
				int f = a[i];
				if(f < x && !st[f])
				{
					st[f] = 1;
					now ++;
				}
				if(now == x)
				{
					cnt ++;
					now = 0;
					memset(st, 0, sizeof st);
				}
			}
			return cnt >= k;
		};

		int l = 0, r = 2e5 + 10;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;

			// cout <<l <<"l and r" <<r <<endl;
			// cout <<"mid " <<mid <<endl;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout <<l <<endl;
	}
	return 0;
}