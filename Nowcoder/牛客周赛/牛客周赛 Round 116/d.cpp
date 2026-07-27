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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> v;
		vector<pii> a(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int l, r; cin >>l >>r;
			a[i] = {l, r};
			v.push_back(l), v.push_back(r);
		}

		auto b = v;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		auto c = a;
		sort(c.begin(), c.end());
		bool f = 1;
		int s = c[0].ff, e = c[0].se;
		for(int i = 1; i < c.size(); i ++)
		{
			auto [l, r] = c[i];
			if(l >= e) e = r;
			else//l < e
			{
				if(r < e)
				{
					f = 0;
					break;
				}
				else e = r;
			}
		}

		if(!f)
		{
			cout <<"No" <<endl;
			continue;
		}

		auto find = [&](int x) -> i32
		{
			return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
		};

		vector<int> diff(400010, 0);
		for(int i = 1; i <= n; i ++)
		{
			auto [l, r] = a[i];
			l = find(l), r = find(r);
			diff[l] ++;
			if(r + 1 < 400010) diff[r + 1] --;
		}
		for(int i = 1; i < 400010; i ++)
			diff[i] += diff[i - 1];
		cout <<(*max_element(diff.begin(), diff.end()) == n ? "Yes" : "No") <<endl;
	}

	return 0;
}