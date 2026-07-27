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
		int n, m, k; cin >>n >>m >>k;
		int w; cin >>w;
		vector<int> a;
		for(int i = 0; i < w; i ++)
		{
			int x; cin >>x;
			a.push_back(x);
		}

        int less = n * m - w;
		for(int i = 0; i < less; i ++)
			a.push_back(0);

		int cnt1 = 4, cnt2 = 2 * (m - 2) + 2 * (n - 2);
		sort(a.begin(), a.end());
		
		vector<int> v;
		vector g(n + 1, vector<int>(m + 1, 0));
		for(int i = 1; i + k - 1 <= n; i ++)
		    for(int j = 1; j + k - 1 <= m; j ++)
		        for(int a = i; a <= i + k - 1; a ++)
		            for(int b = j; b <= j + k - 1; b ++)
		                g[a][b] ++;
		for(int i = 1; i <= n; i ++)
		    for(int j = 1; j <= m; j ++)
		        v.push_back(g[i][j]);
		sort(v.begin(), v.end());
		ll ans = 0;
		for(int i = 0; i < n * m; i ++)
		    ans += 1LL * a[i] * v[i];
		cout <<ans <<endl;
	}
	return 0;
}