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

void solve()
{
	int n, k; cin >>n >>k;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		a[i] = (a[i] <= k) ? -1 : 1;
		pre[i] = pre[i - 1] + a[i];
	}

	if(*min_element(pre.begin() + 2, pre.begin() + n) < 0)
	{
		cout <<"YES" <<endl;
		return ;
	}
	if(count(pre.begin() + 1, pre.begin() + n, 0) > 1)
	{
		cout <<"YES" <<endl;
		return ;
	}
	if(*max_element(pre.begin() + 1, pre.begin() + n - 1) > pre[n])
	{
		cout <<"YES" <<endl;
		return ;
	}
	if(count(pre.begin() + 1, pre.begin() + n - 1, pre[n]) > 1)
	{
		cout <<"YES" <<endl;
		return ;
	}

	int l = 1, r = n - 1;
	while(l < r && pre[l] > 0) l ++;
	while(r > l && pre[n] - pre[r] > 0) r --;

	if(l < r)
	{
		cout <<"YES" <<endl;
		return ;
	}
	cout <<"NO" <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}
	return 0;
}