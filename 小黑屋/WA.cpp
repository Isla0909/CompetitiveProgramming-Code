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
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	freopen("in.txt", "r", stdin);
	freopen("WA.txt", "w", stdout);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), mmin(n + 2), mmax(n + 2);
		int x, y;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		int c1 = *max_element(a.begin() + 1, a.end());
		int c2 = *min_element(a.begin() + 1, a.end());
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == c1) x = i;
			if(a[i] == c2) y = i;
		}

		mmin[1] = a[1];
		for(int i = 2; i <= n; i ++)
			mmin[i] = min(mmin[i - 1], a[i]);
		mmax[n] = a[n];
		for(int i = n - 1; i >= 1; i --)
			mmax[i] = max(mmax[i + 1], a[i]);

		for(int i = 1; i <= n; i ++)
		{
			if(i == x || i == y) cout <<1;
			else
			{
				if(a[i] == mmin[i] and mmax[i + 1] > a[i]) cout <<1;
				else if(a[i] == mmax[i] and mmin[i - 1] < a[i]) cout <<1;
				else cout <<0;
			}
		} 
		cout <<endl;
	}
	return 0;
}