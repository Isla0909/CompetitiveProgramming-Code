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
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void min_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int min_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}

	void gcd_work()
	{
		for(int j = 0; j < k; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
	}
	int gcd_query(int l, int r)
	{
		if(l > r) swap(l, r);
		int k = __lg(r - l + 1);
		return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
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
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		//max[i] == max[i - 1] : bi <= max[i - 1]
		//max[i] > max[i - 1] b[i] = a[i] ? 
		SparseTable st(a);
		st.max_work();

		i64 ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(b[i] == a[i])
			{
				int l = i, r = n + 1 - i;
				ans += 1LL * l * r;
			}
			else
			{

				if(i == 1|| i >= 2 && a[i] > st.max_query(1, i - 1)) continue;
				int x = max(a[i], b[i]);
				int l = 0, r = i;
				while(l + 1 != r)
				{
					int mid = l + r >> 1;
					if(x <= st.max_query(mid, i - 1)) l = mid;
					else r = mid;
				}
				int lc = l, rc = n + 1 - i;
				ans += 1LL * lc * rc;
			}
		}
		cout <<ans <<endl;
	}	
	return 0;
}