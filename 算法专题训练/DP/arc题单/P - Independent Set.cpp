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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
vector <int> adj[N];
int f[N][2];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void dfs(int u, int fa)
{
	f[u][0] = f[u][1] = 1;
	for(auto v : adj[u])
	{
		if(v == fa) continue;
		dfs(v, u);
		f[u][1] = (f[u][1] * f[v][0]) % mod;
		f[u][0] = (f[u][0] * (f[v][1] + f[v][0])) % mod;
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	for(int i = 1; i < n; i ++)
	{
		int a, b; cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, -1);

	cout <<(f[1][0] + f[1][1]) % mod <<endl;
	return 0;
}