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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		bool h = 1;
		for(int i = 0; i < a.size() / 2; i ++)
		{
			if(a[i] != a[n - 1 - i])
			{
				h = 0;
				break;
			}
		}
		if(h)
		{
			cout <<"YES" <<endl;
			continue;
		}

		vector<int> b(a);
		sort(b.begin(), b.end());
		auto get1 = [&](int x) -> int
		{
			return lower_bound(b.begin(), b.end(), x) - b.begin();
		};
		auto get2 = [&](int x) -> int
		{
			return upper_bound(b.begin(), b.end(), x) - b.begin();
		};

		auto judge = [&](vector<pii> &v)
		{
			int n = v.size();
			for(int i = 0; i < n / 2; i ++)
				if(v[i].ff != v[n - 1 - i].ff) return false;
			return true;
		};

		bool f = 0; 
		vector<pii> v;
		for(int i = 0; i < n; i ++)
		{
			if(get2(a[i]) < k) v.push_back({a[i], i + 1});
		}
		
		if(!judge(v))
		{
			cout <<"NO" <<endl;
			continue;
		}
		if(judge(v) && v.size() == k - 1)
		{
			cout <<"YES" <<endl;
			continue;
		}

		if(judge(v) && v.size() == 0)
		{
			cout <<"YES" <<endl;
			continue;
		}

		int x;
		for(int i = 0; i < n; i ++)
		{
			if(get1(a[i]) < k && get2(a[i]) >= k)
			{
				x = a[i];
				break;
			}
		}
		vector<int> cnt(n + 1);
		for(int i = 0; i < n; i ++)
		{
			cnt[i + 1] = cnt[i] + (a[i] == x);
		}
		// for(int i = 0; i < v.size(); i ++)
		// 	cout <<v[i].ff <<" ";
		// cout <<endl;
		int delta = k - 1 - v.size();
		int pre = 0, last = n;
		for(int i = 0; i < (v.size() + 1) / 2; i ++)
		{
			int l = v[i].se, r = v[v.size() - i - 1].se;
			int left = cnt[l] - cnt[pre], right = cnt[last] - cnt[r];
			//cout <<l <<" " <<r <<endl;
			delta -= min(left, right) * 2;
			pre = l, last = r;

			if(i + 1 == v.size() - i - 1)
			{
				l = v[i].se, r = v[v.size() - i - 1].se;
				int c = cnt[r] - cnt[l];
				delta -= c;
			}

			if(delta <= 0)
			{
				f = 1;
				break;
			}
		}
		cout <<(f ? "YES" : "NO") <<endl;
	}
	return 0;
}