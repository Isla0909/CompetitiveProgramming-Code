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

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector <int> a(m), s(m);
		for(auto &x : a) cin >>x;

		sort(a.begin(), a.end());

		s[0] = a[0];
		for(int i = 1; i < m; i ++)
			s[i] = s[i - 1] + a[i];
		// for(auto x : s) cout <<x <<" ";
		// 	cout <<endl;
		ll ans = 0;
		for(int i = 0; i < m; i ++)
		{
			int x = a[i];
			
			int l = i, r = m;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(a[mid] >= n - x) r = mid;
				else l = mid;
			}
			//cout <<r <<" ";
			if(r <= i || r == m) continue;
			
			int idx = lower_bound(a.begin(), a.end(), n) - a.begin();

			if(idx >= r)
			{
				int t = s[idx - 1] - s[r - 1] + (idx - 1 - r + 1) * x;
				t = t + idx - 1 - r + 1 - n * (idx - r);
				ans += t * 2;
			}
			//cout <<idx <<endl;
			int len = m - max(idx, i + 1);
			ans += len * min(x, n - 1) * 2;
		}
		cout <<ans <<endl;
	}
	return 0;
}