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
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m; 
vector <int> a[N];

int get(int x)
{
	int res = 0;
	for(int i = 0; i < m; i ++)
		res += a[x][i];
	return res;
}

bool cmp(pii &a, pii &b)
{
	return a.se > b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		cin >>n >>m;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				int x; cin >>x;
				a[i].push_back(x);
			}
		vector <pii> v;
		for(int i = 1; i <= n; i ++)
			v.emplace_back(i, get(i));

		sort(v.begin(), v.end(), cmp);

		int ans = 0; int k = n * m;
		for(int i = 0; i < n; i ++)
		{
			int idx = v[i].ff;
			for(int j = 0; j < m; j ++)
			{
				ans += k * a[idx][j];
				k --;
			}
		}
		cout <<ans <<endl;

		for(int i = 1; i <= n; i ++)
			a[i].clear();
	}
	return 0;
}