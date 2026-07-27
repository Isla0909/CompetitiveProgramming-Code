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
		int n, f, k; cin >>n >>f >>k;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >>a[i];

		int x = a[f - 1];
		sort(a.begin(), a.end(), greater<int>());

		int l, r;
		for(int i = 0; i < n; i ++)
			if(a[i] == x)
			{
				int j = i;
				while(j + 1 < n && a[j + 1] == x) j ++;
				l = i, r = j;
				break;
			}
		//cout <<"l and r" <<l <<" " <<r <<endl;
		k --;
		if(r <= k) cout <<"YES" <<endl;
		else if(l > k) cout <<"NO" <<endl;
		else cout <<"MAYBE" <<endl;
	}
	return 0;
}