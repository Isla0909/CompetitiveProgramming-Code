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
#define int long long
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int add = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector <int> p(n + 1), son(n + 1), fa(n + 1 + add);
		
		for(int i = 1; i <= n; i ++)
		{
			fa[i] = i + add + add;//部落
			son[i] = i + add;//唯一军权
			p[i] = i + add;//人民
		}

		auto find = [&](int x) -> int
		{
			x = p[x];
			while(x < add * 2) x = fa[x];
			return son[x];
		};

		while(m --)
		{
			int op; cin >>op;
			if(op == 1)
			{
				int a, b; cin >>a >>b;
				fa[son[b]] = son[a];
			}
			else if(op == 2)
			{
				int a, b; cin >>a >>b;
				p[a] = son[b];
				p[a] = find(a);
			}
			else if(op == 3)
			{
				int a, b; cin >>a >>b;
				
				fa[son[a]] = b + add + add;
				fa[son[b]] = a + add + add; 
			}
			else
			{
				int x; cin >>x;
				cout <<fa[find(x) - add] - add - add <<endl;
			}
		}
	}
	return 0;
}