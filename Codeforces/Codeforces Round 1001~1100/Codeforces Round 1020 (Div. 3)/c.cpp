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
#include <functional>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n), b(n);
		for(auto &x : a) cin >>x;
		for(auto &x : b) cin >>x;

		int x = -1; bool f = 1;
		for(int i = 0; i < n; i ++)
		{
			if(b[i] != -1)
			{
				if(x == -1) x = a[i] + b[i];
				else if(a[i] + b[i] != x)
				{
					f = 0;
					break;
				}
			}
		}

		for(int i = 0; i < n; i ++)
		{
			if(!f || x == -1) break;
			if(b[i] == -1)
			{
				int j = x - a[i];
				if(j > k || j < 0)
				{
					f = 0;
					break;
				}
			}
		}

		if(!f) cout <<0 <<endl;
		else
		{
			bool h = 1;
			for(auto c : b)
				if(c != -1)
				{
					h = 0;
					break;
				}
			if(!h) cout <<1 <<endl;
			else
			{
				int c = *min_element(a.begin(), a.end()) + k - *max_element(a.begin(), a.end());
				if(c < 0) cout <<-1 <<endl;
				else cout <<c + 1 <<endl;
			}
		}
	}
	return 0;
}