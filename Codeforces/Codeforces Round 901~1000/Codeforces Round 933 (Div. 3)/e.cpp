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
	return a.se < b.se;
}

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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k, d; cin >>n >>m >>k >>d;
		vector f(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>f[i][j];
		vector <int> a(n + 1, 0), s(n + 1, 0);
		for(int i = 1; i <= n; i ++)
		{
			a[i] += 2; int l = 1;
			while(l + 1 + d < n)
			{
				int h = INF, x;
				for(int j = l + 1 + 1; j <= l + 1 + d; j ++)
					if(f[i][j] <= h)
					{
						h = f[i][j];
						x = j;
					}
				a[i] += h, x = 
			}
		}
	}
	return 0;
}