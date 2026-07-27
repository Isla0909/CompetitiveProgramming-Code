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
		string a, b; cin >>a >>b;
		bool f = 1;
		int s1 = 0, s2 = 0;
		for(int i = 0; b[i]; i ++)
		{
			if(i & 1 && b[i] == '0') s1 ++;
			else if(i % 2 == 0 && b[i] == '0') s2 ++;
		}
		for(int i = 0; a[i]; i ++)
		{
			if(a[i] == '1')
			{
				if(i & 1)
				{
					if(s2) s2 --;
					else
					{
						f = 0;
						break;
					}
				}
				else
				{
					if(s1) s1 --;
					else
					{
						f = 0;
						break;
					}
				}
			}
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}