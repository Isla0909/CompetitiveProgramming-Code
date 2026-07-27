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
		int n; cin >>n;
		vector<pii> v(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>v[i].ff;
			v[i].se = i;
		}
		vector<int> l(n), r(n);
		r[0] = v[1].ff, l[n - 1] = v[n - 2].ff;
		for(int i = 1; i < n - 1; i ++)
		{
			l[i] = v[i - 1].ff;
			r[i] = v[i + 1].ff;
		}
		// for(int i = 0; i < n; i ++)
		// 	cout <<l[i] <<" " <<r[i] <<endl;
		sort(v.begin(), v.end(), greater<pii>());
		int ans = -1;
		for(int i = 0; i < n; i ++)
		{
			int idx = v[i].se;
			if(l[idx] > v[i].ff && r[idx] > v[i].ff)
			{
				ans = max(ans, min(l[idx], r[idx]));
				//break;
			}
			else if(l[idx] >= v[i].ff || r[idx] >= v[i].ff)
			{
				ans = max(ans, v[i].ff);
				//break;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}