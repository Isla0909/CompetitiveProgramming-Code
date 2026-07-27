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
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m; 
int d[N], din[N]; int mmax = -1;
bool st[N];
vector <int> adj[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void topsort()
{
	queue <int> q;
	for(int i = 1; i <= n; i ++)
		if(!din[i]) q.push(i);

	while(q.size())
	{
		auto t = q.front(); q.pop();
		//cout <<t <<endl;
		for(auto x : adj[t])
		{
			din[x] --;
			if(d[x] <= d[t] + 1)
			{
				d[x] = d[t] + 1;
				if(d[x] > mmax) mmax = d[x];
				//cout <<t <<" "  <<x <<endl;
			}
			if(!din[x]) q.push(x);
		}
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	cin >>n >>m;
	while(m --)
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		din[b] ++;
	}

	topsort();

	cout <<mmax <<endl;
	return 0;
}