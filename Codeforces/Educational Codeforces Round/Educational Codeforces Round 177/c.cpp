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
using namespace std;
using u32 = unsigned;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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
		int n; cin >>n;
		vector<int> a(n + 1), d(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		vector<bool> st(n + 1, 0);
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>d[i];
			if(!st[d[i]] && a[d[i]] == d[i]) cnt ++;
			else if(!st[d[i]])
			{
				int x = d[i]; 
				while(!st[x])
				{
					cnt ++;
					st[x] = 1;
					x = a[x];
				}
			}
			cout <<cnt <<" ";
		}
		cout <<endl;
	}
	return 0;
}