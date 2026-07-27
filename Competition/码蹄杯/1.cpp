#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int x, vector<int> &v)
{
	for(int i = 0; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<pii> v;
	for(int i = 0; i < n; i ++)
	{
		int l, r; cin >>l >>r;
		v.emplace_back(l, r);
	}

	sort(v.begin(), v.end());
	i64 ans = 0;
	int st = v[0].ff, ed = v[0].se;
	for(int i = 1; i < n; i ++)
	{
		auto [l, r] = v[i];
		if(l <= ed + 1) ed = max(r, ed);
		else
		{
			ans += ed - st + 1;
			st = l, ed = r;
		} 
	}
	ans += ed - st + 1;
	cout <<ans <<endl;
	return 0;
}