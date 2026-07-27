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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int p1[N], p2[N];

int find1(int x)
{
	if(x != p1[x]) p1[x] = find1(p1[x]);
	return p1[x];
}

int find2(int x)
{
	if(x != p2[x]) p2[x] = find2(p2[x]);
	return p2[x];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m1, m2; cin >>n >>m1 >>m2;

		for(int i = 1; i <= n; i ++) p1[i] = p2[i] = i;
		vector <pii> v;
		for(int i = 0; i < m1; i ++)
		{
			int a, b; cin >>a >>b;
			v.emplace_back(a, b);
		}
		for(int i = 0; i < m2; i ++)
		{
			int a, b; cin >>a >>b;
			v.emplace_back(a, b);
			if(find2(a) != find2(b)) p2[find2(a)] = b;
		}
		int cnt = 0;
		for(int i = 0; i < m1 + m2; i ++)
		{
			int a = v[i].ff, b = v[i].se;
			if(i < m1)
			{
				int fa1 = find1(a), fb1 = find1(b), fa2 = find2(a), fb2 = find2(b);
				if(fa2 == fb2 && fa1 != fb1) p1[fa1] = fb1;
				else if(fa2 != fb2) cnt ++;
			}
			else
			{
				int fa1 = find1(a), fb1 = find1(b);
				if(fa1 != fb1)
				{
					p1[fa1] = fb1;
					cnt ++;
				}
			}
		}
		cout <<cnt <<endl;
	}
	return 0;
}