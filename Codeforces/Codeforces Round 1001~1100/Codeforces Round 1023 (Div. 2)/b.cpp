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
	return a.ff > b.ff;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n);
		for(auto &x : a) cin >>x;
		int mmax = *max_element(a.begin(), a.end()), mmin = *min_element(a.begin(), a.end());
		int cnt1 = 0, cnt2 = 0;
		for(auto x : a)
		{
			if(x == mmax) cnt1 ++;
			if(x == mmin) cnt2 ++;
		}
		int m = mmax - mmin;
		if(m == k + 1)
		{
			if(cnt1 == 1)
			{
				ll sum = 0;
				for(int i = 0; i < n; i ++)
					sum += a[i];
				if(sum & 1) cout <<"Tom" <<endl;
				else cout <<"Jerry" <<endl;
			}
			else cout <<"Jerry" <<endl;
		}
		else if(m > k + 1) cout <<"Jerry" <<endl;
		else
		{
			ll sum = 0;
			for(int i = 0; i < n; i ++)
				sum += a[i];
			if(sum & 1) cout <<"Tom" <<endl;
			else cout <<"Jerry" <<endl;
		}
 	}
	return 0;
}