#include <bits/stdc++.h>
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

ll get(vector<ll> &a)
{
	ll sum = -inf, ans = -inf;
	for(auto x : a)
	{
		sum = max(0LL, sum) + x;
		ans = max(ans, sum);
	}
	return ans;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; ll k; cin >>n >>k;
		string s; cin >>s;

		vector<ll> a(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>a[i];
			if(s[i] == '0') a[i] = -inf;
		}

		ll res = get(a);
		if(res > k)
		{
			cout <<"No" <<endl;
			continue;
		}
		int x = s.find('0');
		if(x == -1)
		{
			if(res == k)
			{
				cout <<"Yes" <<endl;
				for(int i = 0; i < n; i ++)
					cout <<a[i] <<" \n"[i == n - 1];
			}
			else cout <<"No" <<endl;
		}
		else
		{
			a[x] = inf;
			res = get(a);
			a[x] -= (res - k);
			cout <<"Yes" <<endl;
			for(int i = 0; i < n; i ++)
				cout <<a[i] <<" \n"[i == n - 1];
		}
	}
	return 0;
}