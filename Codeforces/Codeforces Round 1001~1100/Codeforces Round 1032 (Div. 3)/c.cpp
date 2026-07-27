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
		int n, m; cin >>n >>m;
		vector g(n, vector<int>(m));
		int f_max = -1, se_max = -1;
		for(int i = 0; i < n; i ++) 
			for(int j = 0; j < m; j ++)
			{
				int x; cin >>x;
				g[i][j] = x;
				if(x > f_max) se_max = f_max, f_max =x;
				else if(x > se_max && x != f_max) se_max = x;
			}

		if(n * m == 1) cout <<g[0][0] - 1 <<endl;
		else
		{
			int cnt = 0, cc = 0;
			vector<int> r1(n), c1(m), r2(n), c2(m);
			for(int i = 0; i < n; i ++)
				for(int j = 0; j < m; j ++)
				{
					if(g[i][j] == f_max) r1[i] ++, c1[j] ++, cnt ++;
					if(g[i][j] == se_max) r2[i] ++, c2[j] ++, cc ++;
				}

			int ans = f_max;
			for(int i = 0; i < n; i ++)
			{
				for(int j = 0; j < m; j ++)
				{
					int f = (g[i][j] == f_max);
					if(r1[i] + c1[j] - f == cnt)
					{
						ans = min(ans, f_max - 1);
					}
				}
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}