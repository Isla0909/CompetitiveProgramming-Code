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
		int n; cin >>n;
		vector<pii> a(n), b(n), c(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>a[i].ff;
			a[i].se = i;
		}
		for(int i = 0; i < n; i ++)
		{
			cin >>b[i].ff;
			b[i].se = i;
		}
		for(int i = 0; i < n; i ++)
		{
			cin >>c[i].ff;
			c[i].se = i;
		}
		sort(a.begin(), a.end(), greater<>());
		sort(b.begin(), b.end(), greater<>());
		sort(c.begin(), c.end(), greater<>());

		vector<pii> v1, v2, v3;
		for(int i = 0; i < min(10, n); i ++)
		{
			v1.emplace_back(a[i]);
			v2.emplace_back(b[i]);
			v3.emplace_back(c[i]);
		}

		int ans = 0;
		for(int i = 0; i < v1.size(); i ++)
		{
			for(int j = 0; j < v2.size(); j ++)
			{
				for(int k = 0; k < v3.size(); k ++)
				{
					if(v1[i].se != v2[j].se && v1[i].se != v3[k].se && v2[j].se != v3[k].se)
					{
						ans = max(ans, v1[i].ff + v2[j].ff + v3[k].ff);
					}
				}
			}
		}
		cout <<ans <<endl; 	
	}
	return 0;
}