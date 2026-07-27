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

	int n, m; cin >>n >>m;
	vector<int> a(m + 2);
	for(int i = 1; i <= m; i ++) cin >>a[i];

	a[0] = 0, a[m + 1] = n + 1;
	vector f(m + 2, vector<int>(m + 2, 0));
	for(int len = 1; len <= m; len ++)
	{
		for(int i = 1; i + len - 1 <= m; i ++)
		{
			int l = i, r = i + len - 1;
			if(l == r)
				f[l][r] = a[i + 1] - a[i - 1] - 1 - 1;
			else
			{
				f[l][r] = INF;
				for(int k = l + 1; k <= r; k ++)
					f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + a[r + 1] - a[l - 1] - 1 - 1);
			}
			cout <<l <<" " <<r <<" " <<f[l][r] <<endl;
		}
	}
	cout <<f[1][m] <<endl;
	return 0;
}