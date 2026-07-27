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
		int n, m; cin >>n >>m;
		vector g(n, vector<char>(m));
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				cin >>g[i][j];
		bool f = 1;
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				if(g[i][j] == '1')
				{
					bool f1 = 1, f2 = 1;
					for(int k = 0; k < j; k ++)
						if(g[i][k] != '1')
						{
							f1 = 0;
							break;
						}
					for(int k = 0; k < i; k ++)
						if(g[k][j] != '1')
						{
							f2 = 0;
							break;
						}
					if(!f1 && !f2)
					{
						f = 0;
						break;
					}
				}
			}
			if(!f) break;
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}