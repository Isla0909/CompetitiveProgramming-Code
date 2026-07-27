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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se > b.se;
}

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" ";
	cout <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector <int> a(n + 1), d(m + 1), f(k + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= m; i ++) cin >>d[i];
		for(int i = 1; i <= k; i ++) cin >>f[i];

		sort(d.begin() + 1, d.end()), sort(f.begin() + 1, f.end());

		//tell(d); 
		//tell(f);
		//cout <<endl;

		vector <pii> v;
		for(int i = 1; i < n; i ++) v.emplace_back(i, a[i + 1] - a[i]);

		sort(v.begin(), v.end(), cmp);

		int l = a[v[0].ff], r = a[v[0].ff + 1];
		//cout <<l <<"l and r" <<r <<endl;
		int ans = r - l;
		for(int i = 1; i <= m; i ++)
		{
			int ll = l - d[i], rr = r - d[i];
			//cout <<ll <<"ll and rr" <<rr <<endl;
			int x1 = ll + (r - l + 1) / 2, x2 = rr - (r - l + 1) / 2;
			//cout <<x1 <<" " <<x2 <<endl;
			if(x1 == x2)
			{
				auto it = lower_bound(f.begin() + 1, f.end(), x1);
				if(it != f.end()) ans = min(ans, max(r - d[i] - *it, *it - (l - d[i])));
				if(it != f.begin() + 1)
				{
					it --; 
					ans = min(ans, max(r - d[i] - *it, *it - (l - d[i])));
				}
			}
			else
			{
				auto it1 = lower_bound(f.begin() + 1, f.end(), x1);
				auto it2 = lower_bound(f.begin() + 1, f.end(), x2);
				if(it1 != f.end()) ans = min(ans, max(r - d[i] - *it1, *it1 - (l - d[i])));
				if(it1 != f.begin() + 1)
				{
					it1 --; ans = min(ans, max(r - d[i] - *it1, *it1 - (l - d[i])));
				}
				if(it2 != f.end()) ans = min(ans, max(r - d[i] - *it2, *it2 - (l - d[i])));
				if(it2 != f.begin() + 1)
				{
					it2 --; ans = min(ans, max(r - d[i] - *it2, *it2 - (l - d[i])));
				}
			}
			if(ans == (r - l + 1) / 2) break;
		}
		if(n >= 3) ans = max(ans, a[v[1].ff + 1] - a[v[1].ff]);
		cout <<ans <<endl;
	}
	return 0;
}