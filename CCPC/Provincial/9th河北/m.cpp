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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int lowbit(int x)
{
	return x & -x;
}

int count1(int x)
{
	return __builtin_popcount(x);
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<string> v(m);
	for(int i = 0; i < m; i ++) 
		cin >>v[i];

	int a, b, c, d, e, f; cin >>a >>b >>c >>d >>e >>f;
	bool h = 0; bool first = 1;
	for(int i = (1 << 10) - 1; i < (1 << 18); i ++)
	{
		if(count1(i) > 13 || count1(i) < 10) continue;

		vector<int> cnt;
		for(int j = 0; j < m; j ++)
		{
			int solve = 0;
			for(int k = 0; k < n; k ++)
				if(i >> (n - k - 1) & 1 && v[j][k] == '1') solve ++;
			cnt.push_back(solve);
		}
	
		sort(cnt.begin(), cnt.end());
		
		auto get = [&](int x) -> int
		{
			int less = lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
			return m - less;
		};

		if(get(d) >= a && get(d + 1) < a && get(e) >= b && get(e + 1) < b && get(f) >= c && get(f + 1) < c)
		{
			h = 1;
			vector<int> ans;
			for(int k = 0; k < n; k ++)
				if(i >> (n - k - 1) & 1) ans.push_back(k + 1);

			cout <<ans.size() <<endl;
			for(int i = 0; i < ans.size(); i ++)
				cout <<ans[i] <<" \n"[i == ans.size() - 1];
			break;
		}
	}
	if(!h) cout <<-1 <<endl;
	return 0;
}