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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		sort(a.begin() + 1, a.end(), greater<int>());

		int ans = 0, now = 0, cnt = 0;
		int l = 1, r = n + 1; bool f = 0;
		while(l < r)
		{
			a[l] --; ans ++;
			cnt ++;

			if(cnt == n) break;

			if(k - now > a[l])
			{
				now += a[l];
				ans += a[l];
				l ++;
			}
			else
			{
				while(k - now <= a[l])
				{
					a[l] -= k - now; ans += k - now;
					now = 0;
					r --; cnt ++;
					//cout <<a[l] <<" " <<cnt <<" " <<ans <<endl;

					if(cnt == n)
					{
						f = 1;
						break;
					}
				}
				if(f) break;
				now += a[l];
				ans += a[l];
				l ++;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}