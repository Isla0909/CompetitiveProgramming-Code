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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector <int> a(n), b(n);
		for(int i = 0; i < n; i ++) cin >>a[i];
		for(int i = 0; i < n; i ++) cin >>b[i];

		vector <pii> v;
		for(int i = 0; i < n; i ++)
			v.emplace_back(a[i], b[i]);
		sort(v.begin(), v.end());
		if(v[n - 1].se) cout <<v[n - 1].ff + k + v[(n + 1) / 2 - 1].ff <<endl;
		else
		{
			
		}
	}
	return 0;
}