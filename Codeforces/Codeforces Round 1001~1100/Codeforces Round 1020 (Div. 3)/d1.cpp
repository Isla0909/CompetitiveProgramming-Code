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
		int n, m; cin >>n >>m;
		vector<int> a(n + 1), b(m + 1);;
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= m; i ++) cin >>b[i];

		vector<int> l(m + 2, INF), r(m + 2, -1);
		l[0] = 0, r[m + 1] = INF;
		for(int i = 1, j = 1; i <= m; i ++)
		{
			while(j <= n && a[j] < b[i]) j ++;
			if(j > n) break;
			l[i] = j ++;
		}
		for(int i = m, j = n; i >= 1; i --)
		{
			while(j >= 1 && a[j] < b[i]) j --;
			if(j <= 0) break;
			r[i] = j --;
		}

		if(l[m] <= n) cout <<0 <<endl;
		else
		{
			int ans = INF;
			for(int i = 1; i <= m; i ++)
				if(l[i - 1] < r[i + 1])
					ans = min(ans, b[i]);
			cout <<(ans == INF ? -1 : ans) <<endl;
		}
	}
	return 0;
}