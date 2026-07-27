#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <array>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector p(3, vector<int>(n)), up(3, vector<int>(n));
		for(int i = 0; i < 3; i ++)
			for(int j = 0; j < n; j ++)
			{
				cin >>p[i][j];
				p[i][j] --;//该数j在i心中的地位
				up[i][p[i][j]] = j;
				//地位p[i][j]在i心中对应的数
			}
		vector<array<int, 2>> g(n, {-1, -1});
		g[0] = {0, 0};
		int level[3] = {p[0][0], p[1][0], p[2][0]};
		for(int i = 1; i < n; i ++)
		{
			for(int j = 0; j < 3; j ++)
			{
				if(level[j] > p[j][i])
					g[i] = {j, up[j][level[j]]};
			}
			if(g[i][0] != -1)
			{
				for(int j = 0; j < 3; j ++)
					level[j] = max(level[j], p[j][i]);
			}
		}
		if(g[n - 1][0] == -1) cout <<"NO" <<endl;
		else
		{
			vector<array<int, 2>> ans;
			for(int i = n - 1; i; )
			{
				auto [j, x] = g[i];
				ans.push_back({j, i});
				i = x;
			}
			reverse(ans.begin(), ans.end());
			cout <<"YES" <<endl;
			cout <<ans.size() <<endl;
			for(auto [j, x] : ans)
				cout <<"qkj"[j] <<" " <<x + 1 <<endl;
		}
	}	
	return 0;
}