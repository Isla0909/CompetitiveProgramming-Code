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
		int n, a, b; cin >>n >>a >>b;
		string s; cin >>s;
		int x = 0, y = 0;
		for(int i = 0; s[i]; i ++)
		{
			int t = s[i];
			if(t == 'N') y ++;
			else if(t == 'E') x ++;
			else if(t == 'S') y --;
			else x --;
		}
		//cout <<x <<" " <<y <<endl;
		int xx = 0, yy = 0; bool f = 0;
		for(int i = 0; s[i]; i ++)
		{
			int t = s[i];
			if(t == 'N') yy ++;
			else if(t == 'E') xx ++;
			else if(t == 'S') yy --;
			else xx --;
			for(int k = 0; k <= 20; k ++)
			{
				if(xx + x * k == a && y * k + yy == b)
				{
					f = 1;
					break;
				}
			}
			if(f) break;
		}
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}