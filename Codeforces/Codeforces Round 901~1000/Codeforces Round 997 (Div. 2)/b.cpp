#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define st begin()
#define ed end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 10, INF = 0x3f3f3f3f;
char g[N][N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				cin >>g[i][j];

		int s[n + 1] = {0};
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
				if(g[i][j] == '1') s[i] ++;
			
		vector <int> v; v.push_back(n);
		for(int i = n - 1; i; i --)
		{
			int x = s[i];
			v.insert(v.begin() + x, i);
		}
		reverse(v.begin(), v.end());
		for(auto x : v)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}