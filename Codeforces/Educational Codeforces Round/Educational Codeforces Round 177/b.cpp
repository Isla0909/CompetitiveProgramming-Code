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
		int n, k, x; cin >>n >>k >>x;
		int s = 0;
		int a[n + 1];
		for(int i = 0; i < n; i ++)
		{
			int t; cin >>t;
			a[i + 1] = t;
			s += t;
		}
		int p = x / s, less = x % s, q = 0;
		for(int i = n; i >= 1; i --)
		{
			if(less > 0)
			{
				less -= a[i];
				q ++;
			}
			else break;
		}
		int cnt = p * n + q;
		if(n * k - cnt + 1 > 0) cout <<n * k - cnt + 1 <<endl;
		else cout <<0 <<endl;
	}
	return 0;
}