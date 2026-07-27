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
		int n; cin >>n;

		vector<int> a(n);
		for(auto &x : a) cin >>x;

		a.erase(unique(a.begin(), a.end()), a.end());

		n = a.size();

		vector<pii> v(n);
		for(int i = 0; i < n; i ++)
		{
			v[i].ff = a[i];
			v[i].se = i;
		}
		
		sort(v.begin(), v.end(), cmp);

		vector<bool> st(n + 1, 0);

		int cnt = 0;
		for(int i = 0; i < n; i ++)
		{
			int j = v[i].se;
			if(j + 1 < n && st[j + 1]) st[j] = 1;
			if(j - 1 >= 0 && st[j - 1]) st[j] = 1;

			if(!st[j])
			{
				st[j] = 1;
				cnt ++;
			}
		}
		cout <<cnt <<endl;
	}
	return 0;
}