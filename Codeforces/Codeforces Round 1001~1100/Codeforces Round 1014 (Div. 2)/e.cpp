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

ll quick_pow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		ll n, m, k; cin >>n >>m >>k;
		ll cnt = 0, h = 0;
		for(int i = 0; i < k; i ++)
		{
			int x, y, c; cin >>x >>y >>c;
			if((x == 1 || x == n) ^ (y == 1 || y == m))
				cnt ++, h ^= c; 
		}
		if(cnt == 2 * (n + m) - 4 - 4)//奇数位填满
		{
			if(h) cout <<0 <<endl;
			else cout <<quick_pow(2, n * m - k) <<endl;
		}
		else cout <<quick_pow(2, n * m - k - 1) <<endl;
	}
	return 0;
}