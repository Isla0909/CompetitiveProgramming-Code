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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s; s = ' ' + s;
		vector<int> prea(n + 1), preb(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			prea[i] = prea[i - 1], preb[i] = preb[i - 1];
			if(s[i] == 'a') prea[i] ++;
			else preb[i] ++; 
		}
		int s1 = prea[n], s2 = preb[n];
		if(s1 == s2)
		{
			cout <<0 <<endl;
			continue;
		}
		int x = s1 - s2; int c = 0;
		int ans = n;
		map<int, int> mp; mp[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(s[i] == 'a') c ++;
			else c --;

			int l = c - x;

			if(mp.count(l)) ans = min(ans, i - mp[l]);
			//cout <<i <<" " <<c <<" " <<l <<" " <<ans <<endl;
			mp[c] = i;
		}
		cout <<(ans == n ? -1 : ans) <<endl; 
	}
	return 0;
}