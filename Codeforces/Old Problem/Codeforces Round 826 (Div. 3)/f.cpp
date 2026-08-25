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
		vector<array<int, 4>> seg;
		seg.reserve(n);
		for(int i = 0; i < n; i ++)
		{
			int l, r, c; cin >>l >>r >>c;
			seg.push_back({l, r, c, i});
		}
		vector<int> ans(n, INF);
		sort(seg.begin(), seg.end(), [&](const auto &a, const auto &b)
		{
			return a[0] < b[0];
		});

		int last1 = -1, c1 = -1;
		int last2 = -1, c2 = -1;

		auto add_max = [&](int r, int c)
		{
			if(c == c1) last1 = max(last1, r);
			else if(c == c2)
			{
				last2 = max(last2, r);

				if(last2 > last1)
				{
					swap(last1, last2);
					swap(c1, c2);
				}
			}
			else
			{
				if(r > last1)
				{
					last2 = last1;
					c2 = c1;

					last1 = r, c1 = c;
				}
				else if(r > last2)
				{
					last2 = r;
					c2 = c;
				}
			}
		};


		for(auto [l, r, c, id] : seg)
		{
			int last = (c != c1 ? last1 : last2);
			if(last != -1) ans[id] = min(ans[id], max(0, l - last));

			add_max(r, c);
		}

		last1 = last2 = INF;
		c1 = c2 = -1;

		auto add_min = [&](int l, int c)
		{
			if(c == c1) last1 = min(last1, l);
			else if(c == c2)
			{
				last2 = min(last2, l);

				if(last2 < last1)
				{
					swap(last1, last2);
					swap(c1, c2);
				}
			}
			else
			{
				if(l < last1)
				{
					last2 = last1;
					c2 = c1;

					last1 = l, c1 = c;
				}
				else if(l < last2)
				{
					last2 = l;
					c2 = c;
				}
			}
		};

		for(int i = n - 1; i >= 0; i --)
		{
			auto [l, r, c, id] = seg[i];
			int last = (c != c1 ? last1 : last2);

			if(last != INF) ans[id] = min(ans[id], max(0, last - r));

			add_min(l, c);
		}
		tell(0, ans);
	}
	return 0;
}
