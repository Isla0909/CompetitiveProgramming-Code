#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define int ll
const int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int w[], int n)
{
	for(int i = 0; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

map <char, int> mp = {{'Y', 1}, {'E', 2}, {'S', 3}, {'N', 4}, {'O', 5}};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;

		int n = s.size();
		vector <vector<ll>> cnt(6, vector<ll> (n, 0));
		vector <ll> w(n), d1(n + 1, 0), d2(n + 1, 0), w1(n, 0), w2(n, 0);

		ll s1 = 0, s2 = 0;
		for(int i = 0; s[i]; i ++)
		{
			int t = mp[s[i]];
			for(int j = 1; j <= 5; j ++)
			{
				if(j == t) continue;

				if(!i) cnt[j][i] = 0;
				else cnt[j][i] = cnt[j][i - 1];
			}
			if(!i) cnt[t][i] = 1;
			else cnt[t][i] = cnt[t][i - 1] + 1;
		}
		for(int i = 0; i < n; i ++)
		{
			int t = mp[s[i]];
			if(!t) w[i] = 0;
			else if(t == 2)
			{
				w[i] = (ll)cnt[1][i] * (cnt[3][n - 1] - cnt[3][i]);
				s1 += w[i];
				d1[0] += cnt[3][n - 1] - cnt[3][i], d1[i] -= cnt[3][n - 1] - cnt[3][i];
				d2[i + 1] += cnt[1][i], d2[n] -= cnt[1][i];
			}
			else if(t == 4) w[i] = cnt[5][n - 1] - cnt[5][i];
			else if(t == 5) w[i] = cnt[4][i], s2 += cnt[4][i];
		}
		cout <<s1 <<" " <<s2 <<endl;
		w1[0] = d1[0], w2[0] = d2[0];
		for(int i = 1; i < n; i ++)
		{
			w1[i] = w1[i - 1] + d1[i];
			w2[i] = w2[i - 1] + d2[i];
		}
		for(int i = 0; s[i]; i ++)
		{
			int t = mp[s[i]];
			if(t == 1) w[i] = w1[i];
			if(t == 3) w[i] = w2[i];
		}
		if(s1 == s2) cout <<"DUI DUI DUIMA" <<endl;
		else if(s1 > s2)
		{
			ll h = 0;
			for(int i = 0; s[i]; i ++)
			{
				int t = mp[s[i]];
				if(t == 1 || t == 2 || t == 3)
				{
					h = max(h, w[i] + max(cnt[5][n - 1] - cnt[5][i], cnt[4][i]));
				}
				else if(t == 0)
				{
					h = max(h, max(cnt[5][n - 1] - cnt[5][i], cnt[4][i]));
				}
			}
			if(s1 - h < s2) cout <<"O BUDUI BUDUI" <<endl;
			else cout <<"DUI DE" <<endl;
		}
		else //s1 < s2
		{
			vector <ll> max1(n, 0), max2(n, 0);
			int x = mp[s[0]], y = mp[s[n - 1]];
			if(x >= 4) max1[0] = w[0];
			else max1[0] = 0;
			if(y >= 4) max2[n - 1] = w[n - 1];
			else max2[n - 1] = 0;
			for(int i = 1; i < n; i ++)
			{
				int t = mp[s[i]];
				if(t >= 4) max1[i] = max(w[i], max1[i - 1]);
				else max1[i] = max1[i - 1];
			}	

			for(int i = n - 2; i >= 0; i --)
			{
				int t = mp[s[i]];
				if(t >= 4) max2[i] = max(w[i], max2[i + 1]);
				else max2[i] = max2[i + 1];
			}
			vector <ll> sum(n);
			if(mp[s[0]] == 2) sum[0] = w[0];
			else sum[0] = 0;

			for(int i = 1; i < n; i ++)
			{
				int t = mp[s[i]];
				if(t == 2) sum[i] = sum[i - 1] + w[i];
				else sum[i] = sum[i - 1];
			}	
			ll h = 0;
			// for(auto x : sum)
			// 	cout <<x <<" ";
			// cout <<endl;
			for(int i = 0; i < n - 1; i ++)
			{
				int t = mp[s[i]];
				if(t == 2)
				{
					if(i == 0 || i == n - 1) continue;
					ll res1 = max1[i - 1] + cnt[3][n - 1] - cnt[3][i];
					ll res2 = max2[i + 1] + cnt[1][i];

					h = max(h, max(res1, res2));
				}
				else if(t == 0)
				{
					h = max(h, sum[n - 1] - sum[i]);
					h = max(h, sum[i]);
					h = max(h, cnt[1][i] * (cnt[3][n - 1] - cnt[3][i]));
				}
			}
			//cout <<h <<endl;
			if(s2 - h < s1) cout <<"O DUI DE" <<endl;
			else cout <<"BUDUI BUDUI" <<endl; 
		}
	}
	return 0;
}