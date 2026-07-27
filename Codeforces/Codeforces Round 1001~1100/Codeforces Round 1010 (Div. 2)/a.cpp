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

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
char g[N][N];

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
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >>g[i][j];
		vector <int> c1(n + 1, 0);
		vector <int> c2(m + 1, 0);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(g[i][j] == '1')
				{
					c1[i] ++, c2[j] ++;
				}
		int s1 = 0, s2 = 0;
		for(int i = 1; i <= n; i ++)
			if(c1[i] & 1) s1 ++;
		for(int j = 1; j <= m; j ++)
			if(c2[j] & 1) s2 ++;
		cout <<max(s1, s2) <<endl;
	}
	return 0;
}