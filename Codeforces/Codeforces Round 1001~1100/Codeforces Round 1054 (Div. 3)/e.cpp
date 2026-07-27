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
#define int long long
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
		int n, k, l, r; cin >>n >>k >>l >>r;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		i64 ans = 0;
		map<int, int> mp; int s = 0;
		for(int i = 1, j = 0, u = 0; i + l - 1 <= n; i ++)
		{
			while(j + 1 <= n && s != k)
			{
				j ++;
				mp[a[j]] ++;
				if(mp[a[j]] == 1) s ++;
			}

			if(j > u)
			{
				u = j;
				while(u + 1 <= n)
				{
					if(!mp[a[u + 1]]) break;
					else u ++;
				}
			}

			//cout <<i <<" " <<j <<" " <<u <<endl;

			int left = min(n, i + l - 1), right = min(n, i + r - 1);
			//cout <<left <<" " <<right <<endl;
			//cout <<"s " <<s <<endl;
			if(s == k)
			{
				ans += max(min(right, u) - max(left, j) + 1, 0LL);
				//cout <<123 <<endl;
			}
			mp[a[i]] --;
			if(!mp[a[i]]) s --;

			//cout <<i <<" " <<ans <<" hh " <<min(right, u) - max(left, j) + 1 <<endl;
		}
		cout <<ans <<endl;
	}
	return 0;
}