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
#include <array>
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

struct SparseTable
{
	int n, k;
	vector<int> a;
	vector<vector<int>> st;

	SparseTable() {}
	SparseTable(vector<int> &v)
	{
		initial(v);
	}

	void initial(vector<int> &v)
	{
		n = v.size() - 1;
		k = __lg(2 * n - 1) + 1;
		a.resize(n + 1);
		for(int i = 1; i <= n; i ++)
			a[i] = v[i];
		st.assign(n + 1, vector<int>(k));
	}

	void max_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int max_query(int l, int r)
	{
		if(l > r) return 0;
		int k = __lg(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		auto calc = [&]() -> vector<int>
		{
			vector<int> v, diff(n + 1);
			map<int, int> mp;

			SparseTable st(a);
			st.max_work();
			for(int i = 1; i <= n; i ++)
			{
				if(mp.count(a[i]))
				{
					int l = mp[a[i]], r = i;
					if(st.max_query(l + 1, r - 1) < a[i])
					{
						diff[l] ++;
						if(r + 1 <= n) diff[r + 1] --;
					}
				}
				mp[a[i]] = i;
			}

			int pre = 0;
			for(int i = 1; i <= n; i ++)
			{
				pre += diff[i];
				if(!pre) v.push_back(i);
			}
			return v;
		};

		auto v = calc();
		if(!v.size())
		{
			cout <<0 <<endl;
			continue;
		}

		int l = v.front(), r = v.back();
		int p = l;
		for(auto pos : v)
			if(a[pos] > a[p]) p = pos;

		vector<pii> ans;
		if(l < n)
		{
			int x = *max_element(a.begin() + l + 1, a.end());
			ans.emplace_back(l, x);
		}
		if(r > 1)
		{
			int x = *max_element(a.begin() + 1, a.begin() + r + 1 - 1);
			ans.emplace_back(r, x);
		}
		ans.emplace_back(p, 1);

		bool f = false;
		for(auto [i, x] : ans)
		{
			int old = a[i];
			a[i] = x;

			bool ok = calc().empty();

			a[i] = old;

			if(ok)
			{
				cout <<1 <<endl;
				cout <<i <<" " <<x <<endl;
				f = true;
				break;
			}
		}
		if(!f)
		{
			cout <<2 <<endl;
			cout <<1 <<" " <<1000000000 <<endl;
			cout <<n <<" " <<1000000000 <<endl;
		}
	}
	return 0;
}
