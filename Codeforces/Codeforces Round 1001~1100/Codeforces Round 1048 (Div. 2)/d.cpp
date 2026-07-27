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
    vector<int> log_table;
    vector<vector<int>> st;

    SparseTable(const vector<int>& arr) 
    {
        n = arr.size();
        k = __lg(n) + 1;
        log_table.resize(n + 1);
        st.resize(k, vector<int>(n));

        // 预处理log2值
        for (int i = 2; i <= n; ++i) {
            log_table[i] = log_table[i / 2] + 1;
        }

        // 初始化稀疏表
        for (int i = 0; i < n; ++i) {
            st[0][i] = arr[i];
        }
        for (int j = 1; j < k; ++j) 
            for (int i = 0; i + (1 << j) <= n; ++i) 
            {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
    }

    int query_min(int l, int r) 
    {
        if (l > r) return INT_MAX;
        int len = r - l + 1;
        int j = log_table[len];
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};


bool cmp(const pii &a, const pii &b)
{
	if(a.ff != b.ff) return a.ff < b.ff;
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> pos;
		for(int i = 1; i <=n - 2; i ++)
			if(a[i] > a[i + 2])
				pos.push_back(i);
		// vector<int> stk;
		// vector<pii> v;
		// for(int i = 1; i <= n; i ++)
		// {
		// 	int x = a[i];
		// 	while(stk.size() && a[stk.back()] <= x) stk.pop_back();
		// 	if(stk.size() >= 2)
		// 	{
		// 		int l = stk[stk.size() - 2], r = i;
		// 		v.emplace_back(l, r);
		// 	}
		// 	stk.push_back(i);
		// }
		// // cout <<ed.size() <<endl;
		// sort(v.begin(), v.end(), cmp);
		// vector<int> s, e;
		// for(auto [l, r] : v)
		// {
		// 	s.push_back(l);
		// 	e.push_back(r);
		// }
		// SparseTable st(e);

		while(q --)
		{
			int l, r; cin >>l >>r;
			if(r - l + 1 <= 2)
			{
				cout <<"YES" <<endl;
				continue;
			}
			int lo = l, hi = r - 2;
			auto it = lower_bound(pos.begin(), pos.end(), l);
			if(it != pos.end() && *it <= hi) cout <<"NO" <<endl;
			else cout <<"YES" <<endl;
		}
		// SparseTable st(a);
		// st.max_work();

		// vector<pii> v;
		// vector<int> bad;
		// for(int i = 3; i <= n; i ++)
		// {
		// 	if(st.max_query(1, i - 2) > a[i])
		// 	{
		// 		v.emplace_back(i - 2, i);
		// 		bad.push_back(i - 2);
		// 	}
		// }

		// while(q --)
		// {
		// 	int l, r; cin >>l >>r;
		// 	if(r - l + 1 < 3)
		// 	{
		// 		cout <<"YES" <<endl;
		// 		continue;
		// 	}

		// 	int L = l, R = r - 2;
		// 	auto it = lower_bound(bad.begin(), bad.end(), L);
		// 	if(it != bad.end() && *it <= R) cout <<"NO" <<endl;
		// 	else cout <<"YES" <<endl;
		// }

		// vector<array<int, 3>> query(q + 1);
		// for(int i = 1; i <= q; i ++)
		// {
		// 	int l, r; cin >>l >>r;
		// 	query[i] = {l, r, i};
		// }

		// int len = n / min(n, (int)sqrt(q));
	    // vector<int> bel(n + 1);
	    // for(int i = 1; i <= n; i ++)
	    //     bel[i] = (i - 1) / len + 1;

	    // sort(query.begin() + 1, query.end(), [&](auto a, auto b)
	    // {
	    //     if(bel[a[0]] != bel[b[0]]) return bel[a[0]] < bel[b[0]];
	    //     if(bel[a[0]] & 1) return a[1] < b[1];
	    //     return a[1] > b[1];
	    // });

	    // vector<int> ans(q + 1);
	    // int l = 1, r = 0; i64 val = 0;

	    // Fenwick<int> bit(n);

	    // for(int i = 1; i <= q; i ++)
	    // {
	    // 	auto [ql, qr, id] = query[i];
	    // 	if(qr - ql + 1 <= 2)
	    // 	{
	    // 		ans[id] = 1;
	    // 		continue;
	    // 	}
	    // 	while(l > ql)
	    // 	{
	    // 		int x = a[-- l];
	    // 		val += bit.sum(x - 1);
	    // 		bit.add(x, 1);
	    // 	}
	    // 	while(r < qr)
	    // 	{
	    // 		int x = a[++ r];
	    // 		val += bit.rangeSum(x + 1, n);
	    // 		bit.add(x, 1);
	    // 	}
	    // 	while(l < ql)
	    // 	{
	    // 		int x = a[l ++];
	    // 		val -= bit.sum(x - 1);
	    // 		bit.add(x, -1);
	    // 	}
	    // 	while(r > qr)
	    // 	{
	    // 		int x = a[r --];
	    // 		val -= bit.rangeSum(x + 1, n);
	    // 		bit.add(x, -1);
	    // 	}
	    	
	    // }
	    // for(int i = 1; i <= n; i ++)
	    // 	cout <<(ans[i] ? "YES" : "NO") <<endl;
	}
	return 0;
}