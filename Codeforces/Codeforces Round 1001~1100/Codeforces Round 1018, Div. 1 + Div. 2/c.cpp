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
#define int long long
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
		vector a(n + 1, vector<int>(n + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				cin >>a[i][j];

		auto check = [&](int x, int c) -> bool
		{
			for(int j = 1; j <= n; j ++)
				if(a[x][j] == a[x - 1][j] + c) return false;
			return true;
		};
		vector<int> c(n + 1);
		vector f(n + 1, vector<int>(2, inf));

		int ans = 0;
		for(int i = 1; i <= n; i ++) cin >>c[i];
		f[1][0] = 0, f[1][1] = c[1];
		for(int i = 2; i <= n; i ++)
		{
			if(check(i, 0)) f[i][0] = min(f[i][0], f[i - 1][0]), f[i][1] = min(f[i][1], f[i - 1][1] + c[i]);
			if(check(i, 1)) f[i][0] = min(f[i][0], f[i - 1][1]);
			if(check(i, -1)) f[i][1] = min(f[i][1], f[i - 1][0] + c[i]);
		}
		ans += min(f[n][0], f[n][1]);

		for(int i = 1; i <= n; i ++)
			for(int j = 1; j < i; j ++)
				swap(a[i][j], a[j][i]);
		for(int i = 1; i <= n; i ++) cin >>c[i];

		for(auto &v : f) v[0] = v[1] = inf;

		f[1][0] = 0, f[1][1] = c[1];
		for(int i = 2; i <= n; i ++)
		{
			if(check(i, 0)) f[i][0] = min(f[i][0], f[i - 1][0]), f[i][1] = min(f[i][1], f[i - 1][1] + c[i]);
			if(check(i, 1)) f[i][0] = min(f[i][0], f[i - 1][1]);
			if(check(i, -1)) f[i][1] = min(f[i][1], f[i - 1][0] + c[i]);
		}
		ans += min(f[n][0], f[n][1]);
		if(ans >= inf) cout <<-1 <<endl;
		else cout <<ans <<endl;
	}
	return 0;
}