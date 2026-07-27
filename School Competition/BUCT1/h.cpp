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
using f64 = long double;
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

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	int m; cin >>m;
	vector<vector<int>> v(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int k; cin >>k;
		for(int j = 0; j < k; j ++)
		{
			int x; cin >>x;
			v[i].push_back(x);
		}
	}

	vector<int> used(m + 1), ans;
	bool f = 1;
	function<void(int)> dfs = [&](int i) -> void
	{
		if(!f) return;

		if(ans.size() == m)
		{
			f = false;
			tell(0, ans);
			return;
		}
		
		for(int j = 1; j <= m && f; j ++)
		{
			if(used[j]) continue;

			int k = v[j].size();
			
			if(i + k - 1 > n) continue;

			bool h = true;
			for(int x = 0; x < k; x ++)
			{
				if(v[j][x] != a[i + x])
				{
					h = false;
					break;
				}
			}
			if(!h) continue;

			used[j] = 1;
			ans.push_back(j);

			dfs(i + k - 1);

			used[j] = 0;
			ans.pop_back();
		}
	};
	dfs(1);
	return 0;
}
