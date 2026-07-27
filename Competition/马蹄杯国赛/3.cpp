#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

void solve()
{
	int n, m; cin >>n >>m;
	vector<int> a(n);
	for(auto &x : a) cin >>x;

	auto check = [&](int x) -> bool
	{
		int s = 0;
		for(int i = 0; i < n; i ++)
			s += (a[i] / x);		
		return s <= m;
	};

	int l = 0, r = 1e9 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout <<max(r, 1LL) <<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}

	return 0;
}