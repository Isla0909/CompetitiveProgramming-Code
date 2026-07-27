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
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<i64> &v)
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		map<int, int> cnt;
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			cnt[x] ++;
		}

		for(auto &[x, c] : cnt)
			c %= 2;
		map<int, vector<int>> mp;
		for(auto [x, c] : cnt)
			if(c) mp[x % k].push_back(x);
		

		int s = 0;
		for(auto [r, v] : mp)
			if(v.size() & 1) s ++;
		
		if(s > 1) cout <<-1 <<endl;
		else
		{
			i64 ans = 0;
			for(auto &[r, v] : mp)
			{
				sort(v.begin(), v.end());
				if(v.size() == 1) continue;
				if(v.size() & 1)
				{
					vector<int> b; b.push_back(0);
					for(auto x : v)
						b.push_back(x);
					int m = b.size() - 1;
					vector<i64> pre1(m + 1), pre2(m + 1);
					for(int i = 1; i <= m; i ++)
					{
						pre1[i] = pre1[i - 1], pre2[i] = pre2[i - 1];
						if(i & 1) pre1[i] += b[i];
						else pre2[i] += b[i];
					}
					// for(auto x : b)
					// 	cout <<x <<" ";
					// cout <<endl;
					// tell(0, pre1);
					// tell(0, pre2);
					i64 res = inf;
					for(int i = 1; i <= m; i ++)
					{
						if(i & 1) res = min(res, pre2[i] - pre1[i - 1] + pre1[m] - pre1[i] - (pre2[m] - pre2[i]));
						//if(i & 1) cout <<i <<" " <<pre2[i] - pre1[i - 1] <<" " <<pre1[m] - pre1[i] <<" " <<pre2[m] - pre2[i] <<endl;
					}
					ans += res / k;
				}
				else
				{
					for(int i = 0; i < v.size(); i += 2)
						ans += (v[i + 1] - v[i]) / k;
				}
				// cout <<"ans " <<ans <<endl;
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}