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

void tell(int x, vector<i64> &v)
{
	for(int i = x; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n + 1), b(n + 1);
	vector<i64> prea(n + 1), preb(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		prea[i] = prea[i - 1] ^ a[i];
		prea[i] %= mod;
	}
	for(int j = 1; j <= n; j ++)
	{
		cin >>b[j];
		preb[j] = preb[j - 1] + b[j];
		preb[j] %= mod;
	}

	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
		{
			ans += (preb[j] - preb[i - 1]) * (prea[j] ^ prea[i - 1]) % mod;
			ans %= mod;
		}
	}
	cout <<ans <<endl;
	return 0;
}