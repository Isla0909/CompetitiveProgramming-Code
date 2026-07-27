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
		int n, m, k; cin >>n >>m >>k; 
		vector g(n + 1, vector<int>(m + 1));
		if(m % k == 0)
		{
			for(int j = 1; j <= m; j ++)
				g[1][j] = j % k;
			for(int i = 2; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
				{
					if(j == 1) g[i][j] = g[i - 1][m];
					else g[i][j] = g[i - 1][j - 1];
				}
		}
		else
		{
			int idx = 1;
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
				{
					g[i][j] = idx;
					idx ++;
					if(idx == k + 1) idx = 1;
				}
		}

		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
				if(!g[i][j]) cout <<k <<" ";
				else cout <<g[i][j] <<" ";
			cout <<endl;
		}
	}
	return 0;
}