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
		int n; cin >>n;
		vector <int> a(n);
		for(auto &x : a) cin >>x;

		bool f = 1;
		for(int i = 0; i < n - 2; i ++)
		{
			if(a[i] < 0)
			{
				f = 0;
				break;
			}
			else
			{
				a[i + 1] -= 2 * a[i];
				a[i + 2] -= a[i];
				a[i] = 0;
			}
		}
		if(a[n - 2] != 0 || a[n - 1] != 0) f = 0;
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}