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

bool judge(string s)
{
	int l = s.size();
	for(int i = 0; i <= l / 2; i ++)
		if(s[i] != s[l - 1 - i]) return false;
	return true;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		string s; cin >>s;
		bool h = 0;
		char c = s[0];
		for(int i = 1; i < n; i ++)
			if(s[i] != c)
			{
				h = 1;
				break;
			}
		if(!h)
		{
			cout <<"NO" <<endl;
			continue;
		}

		bool f = 1; int l = s.size();
		if(s.size() == 1) f = 0;
		else if(k == 0 && s[0] > s[l - 1]) f = 0;
		else if(judge(s) && k == 0) f = 0;
		else if(k == 0)
		{
			for(int i = 0; i <= l / 2; i ++)
			{
				int j = l - 1 - i;
				if(s[i] < s[j]) break;
				if(i != j && s[i] > s[j])
				{
					f = 0;
					break;
				}
			}
		}
		else f = 1;

		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
 	return 0;
}