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
#define int long long
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
	return a.ff > b.ff;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		string s; cin >>s;

		vector<int> a(n);
		for(auto &x : a) cin >>x;

		vector<int> v;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '0')
			{
				int pre = 0, suf = 0;
				int j, ans = 0;
				for(j = i - 1; j >= 0 && s[j] == '1'; j --)
				{
					pre += a[j];
					ans = max(pre, ans);
				}
				v.push_back(ans); v.push_back(-1); 
				ans = 0;
				for(int j = i + 1; j < n && s[j] == '1'; j ++)
				{
					suf += a[j];
					//cout <<j <<" " <<suf <<endl;
					ans = max(suf, ans);
				}
				v.push_back(ans);
			}
		}
		//tell(v);
		int f = 0; int idx = -1; int cnt = 0; int x;
		for(int i = 0; i < v.size(); i ++)
		{
			if(v[i] == -1)
			{
				cnt ++;
				int res = max(v[i - 1], v[i + 1]);
				if(res <= k)
				{
					f = 1;
					x = k - v[i - 1] - v[i + 1];
					break;
				}
			} 
		}

		int sum = 0, ans = 0;
		for(int i = 0; i < n; i ++)
		{
			if(s[i] == '0')
			{
				sum = 0;
				continue;
			}
			
			if(sum < 0) sum = 0;
			sum += a[i];
			ans = max(sum, ans);
		}
		//cout <<ans <<endl;
		if(ans == k) f = 2;
		if(ans > k)
		{
			cout <<"No" <<endl;
			continue;
		}

		if(f == 1)
		{
			cout <<"Yes" <<endl;
			for(int i = 0; s[i]; i ++)
			{
				if(s[i] == '1') cout <<a[i] <<" ";
				else
				{
					cnt --;
					if(cnt != 0) cout <<-inf <<" ";
					else cout <<x <<" ";
				}
			}
			cout <<endl;
		}
		else if(f == 2)
		{
			cout <<"Yes" <<endl;
			for(int i = 0; s[i]; i ++)
			{
				if(s[i] == '1') cout <<a[i] <<" ";
				else cout <<-inf <<" ";
			}
			cout <<endl;
		}
		else cout <<"No" <<endl;
 	}
	return 0;
}