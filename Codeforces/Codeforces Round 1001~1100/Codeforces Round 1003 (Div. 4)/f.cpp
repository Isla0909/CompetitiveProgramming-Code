#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5 + 10, INF = 0x3f3f3f3f;
int a[N];
vector <int> adj[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		for(int i = 1; i < n; i ++)
		{
			int x, y; cin >>x >>y;
			adj[x].push_back(y);
			adj[y].push_back(x);		
		}

		vector <int> res(n + 1, 0);
		for(int i = 1; i <= n; i ++)
		{
			map <int, int> mp;

			mp[a[i]] = 1;
			for(auto ver : adj[i]) mp[a[ver]] ++;

			for(auto x : mp)
				if(x.se > 1) res[x.ff] = 1;
		}

		for(int i = 1; i <= n; i ++)
			cout <<res[i];
		cout <<endl;

		for(int i = 1; i <= n; i ++)
			adj[i].clear();

	}
	return 0;
}