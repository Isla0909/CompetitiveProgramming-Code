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
			if(find2(a) != find2(b)) p2[find2(a)] = find2(b);
		}
		int ans = 0;
		for(int i = 0; i < m1 + m2; i ++)
		{
			int a = v[i].ff, b = v[i].se;
			if(i < m1)
			{
				int a1 = find1(a), b1 = find1(b);
				int a2 = find2(a), b2 = find2(b);
				if(a2 == b2 && a1 != b1) p1[a1] = b1;
				else if(a2 != b2) ans ++;
			}
			else
			{
				int a1 = find1(a), b1 = find1(b);
				if(a1 != b1)
				{
				 	ans ++;
				 	p1[a1] = b1;
				}
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
//https://codeforces.com/contest/2060/problem/E