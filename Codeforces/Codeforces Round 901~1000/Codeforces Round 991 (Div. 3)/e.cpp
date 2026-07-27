#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m, q; cin >>n >>m >>q;
	
	vector v(n + 1, vector<int> (m + 1, 0));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		    cin >>v[i][j];
    
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			v[i][j] |= v[i - 1][j];
	
	while(q --)
	{
		int k; cin >>k;
		bool f = 1; int ans_min = 1, ans_max = n;
		while(k --)
		{
			int x, c; char op; cin >>x >>op >>c;
			if(!f) continue;
			
			int l = 0, r = n + 1;
			
			if(op == '>')
			{
				while(l + 1 != r)
				{
					int mid = l + r >> 1;
					if(v[mid][x] <= c) l = mid;
					else r = mid;
				}
				if(l == n) f = 0;
				if(r > ans_max) f = 0;
                
                ans_min = max(ans_min, r);
			}
			else
			{
				while(l + 1 != r)
				{
					int mid = l + r >> 1;
					if(v[mid][x] >= c) r = mid;
					else l = mid;
				}
				if(l == 0) f = 0;
				if(l < ans_min) f = 0;
				
				ans_max = min(ans_max, l);
			}
		}
		if(!f) cout <<-1 <<endl;
		else cout <<ans_min <<endl;
	}
	return 0;
}