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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	
	auto check = [&](int x) -> bool
	{
		for(int i = 1; i + x - 1 <= n; i ++)
		{
			int l = i, r = i + x - 1;
			int cnt = r - l + 1 - (pre[r] - pre[l - 1]);
			if(cnt <= k) return true;
		}
		return false;
	};

	int l = -1, r = n + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}

	int ans = max(0, l);
	cout <<ans <<endl; bool f = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(!f)
		{
			cout <<a[i] <<" ";
			continue;
		}
		int l = i, r = i + ans - 1;
		int cnt = r - l + 1 - (pre[r] - pre[l - 1]);
		if(cnt <= k)
		{
			for(int j = l; j <= r; j ++)
				cout <<1 <<" ";
			i = r, f = 0;
		}
		else cout <<a[i] <<" ";
	}
	cout <<endl;
	return 0;
}