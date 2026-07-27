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

		vector<int> pre(n + 1), suf(n + 2);
		int j = 1, cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(cnt < m && a[i] >= b[j]) j ++, cnt ++;
			
			pre[i] = cnt;
		}
		j = m, cnt = 0;
		for(int i = n; i >= 1; i --)
		{
			if(cnt < m && a[i] >= b[j]) j --, cnt ++;

			suf[i] = cnt;
		}
		if(pre[n] == m) cout <<0 <<endl;
		else
		{
			int ans = INF;
			for(int i = 0; i <= n; i ++)
			{
				if(pre[i] + suf[i + 1] == m - 1)
					ans = min(ans, b[pre[i] + 1]);
			}
			if(ans == INF) ans = -1;
			cout <<ans <<endl;
		}
	}
	return 0;
}