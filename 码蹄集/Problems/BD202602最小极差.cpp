#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i64 = long long;
constexpr long long inf = 1e18;

struct Topk
{
	int k;

	multiset<int> small, big;
	i64 sumbig = 0;

	Topk(int k = 0) : k(k) {}

	void balance()
	{
		while(big.size() > k)
		{
			auto it = big.begin();
			int x = *it;

			sumbig -= x;
			big.erase(it);
			small.insert(x);
		}

		while(big.size() < k && small.size())
		{
			auto it = prev(small.end());
			int x = *it;

			sumbig += x;
			big.insert(x);
			small.erase(it);
		}

		while(small.size() && big.size())
		{
			auto it1 = prev(small.end()), it2 = big.begin();

			int x = *it1, y = *it2;
			if(x <= y) break;

			small.erase(it1);
			big.erase(it2);

			small.insert(y), big.insert(x);

			sumbig += x - y;
		}
	}

	void add(int x)
	{
		small.insert(x);
		balance();
	}

	void del(int x)
	{
		auto it = big.find(x);
		if(it != big.end())
		{
			sumbig -= x;
			big.erase(it);
		}
		else
		{
			it = small.find(x);
			assert(it != small.end());
			small.erase(it);
		}
		balance();
	}

	i64 query()
	{
		return sumbig;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector<i64> a(n + 1);
		vector<pair<i64, int>> v;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			v.emplace_back(a[i], i);
		}

		sort(v.begin(), v.end());

		vector<i64> val;
		vector<vector<int>> pos;
		for(int i = 0, j = 0; i < n; i = j)
		{
			val.emplace_back(v[i].ff);
			pos.push_back({});

			while(j < n && v[j].ff == v[i].ff)
			{
				pos.back().push_back(v[j].second);
				j ++;
			}
		}

		int tot = val.size();
		Topk top(m + 1);
		map<int, int> seg;
		vector<bool> st(n + 2);

		auto add_seg = [&](int l, int r)
		{
			if(l > r) return ;
			seg[l] = r;
			top.add(r - l + 1);
		};

		auto del_seg = [&](map<int, int>::iterator it)
		{
			int l = it -> ff, r = it -> se;
			top.del(r - l + 1);
			seg.erase(it);
		};

		auto add_pos = [&](int p)
		{
			bool hasl = st[p - 1], hasr = st[p + 1];
			st[p] = 1;

			if(!hasl && !hasr) add_seg(p, p);
			else if(hasl && !hasr)
			{
				auto it = prev(seg.upper_bound(p - 1));
				int l = it -> ff;
				del_seg(it);
				add_seg(l, p);
			}
			else if(!hasl && hasr)
			{
				auto it = seg.find(p + 1);
				int r = it -> se;
				del_seg(it);
				add_seg(p, r);
			}
			else
			{
				auto it1 = prev(seg.upper_bound(p - 1)), it2 = seg.find(p + 1);
				int l = it1 -> ff, r = it2 -> se;
				del_seg(it1), del_seg(it2);
				add_seg(l, r);
			}
		};

		auto del_pos = [&](int p)
		{
			auto it = prev(seg.upper_bound(p));
			int l = it -> ff, r = it -> se;

			assert(l <= p && r >= p);

			del_seg(it);
			st[p] = false;

			if(l < p) add_seg(l, p - 1);
			if(r > p) add_seg(p + 1, r);
		};

		i64 ans = inf;
		int r = 0;
		for(int l = 0; l < tot; l ++)
		{
			while(r < tot && top.query() < k)
			{
				for(auto x : pos[r])
					add_pos(x);
				r ++;
			}
			if(top.query() >= k) ans = min(ans, val[r - 1] - val[l]);

			for(auto p : pos[l])
				del_pos(p);
		}
		cout <<ans <<endl;
	}
	return 0;
}
