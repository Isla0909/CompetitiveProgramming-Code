#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using i128 = __int128;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; i64 s; cin >>n >>k >>s;
		vector<i64> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++)
			cin >>a[i] >>b[i];

		vector<int> st(n + 1, 1);

		int f = 0;
		while(true)
		{
			for(int i = 1; i <= n; i ++)
			{
				if(!st[i]) continue;
				if(s >= a[i])
				{
					f = 1;
					s += b[i];
					st[i] = 0;
					break;
				}
			}
			if(!f)
			{
				if(!k) break;
				k --;
				s *= 2;
			}
			f = 0;
		}
		cout <<s <<endl;
	}
	return 0;
}