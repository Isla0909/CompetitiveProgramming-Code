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
		int n, k, x; cin >>n >>k >>x;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		auto check = [&](int c) -> bool
		{
			vector<pii> v;
			for(int i = 1; i <= n; i ++)
			{
				int l = max(0, a[i] - c), r = min(x, a[i] + c);
				if(l <= r) v.emplace_back(l, r);
			}
			sort(v.begin(), v.end());
			int st = -1; int cnt = 0;
			for(auto [l, r] : v)
			{
				if(l <= st + 1) st = max(r, st);
				else
				{
					cnt += l - (st + 1);
					st = r;
				}
			}
			cnt += x - st;
			return cnt >= k;
		};

		int l = -1, r = x + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		} 

		if(l == -1)
		{
			for(int i = 0; i < k; i ++)
				cout <<i <<" \n"[i == k - 1];
			continue;
		}
		//cout <<"l: " <<l <<endl;
		int c = l;
		vector<pii> v, ans;
		for(int i = 1; i <= n; i ++)
		{
			int l = max(0, a[i] - c), r = min(x, a[i] + c);
			v.emplace_back(l, r);
		}
		sort(v.begin(), v.end());
		int st = -1;
		for(auto [l, r] : v)
		{
			if(l <= st + 1) st = max(r, st);
			else
			{
				ans.emplace_back(st + 1, l - 1);
				st = r;
			}
		}
		if(st + 1 <= x) ans.emplace_back(st + 1, x);

		int now = 0;
		for(auto [l, r] : ans)
		{
			//cout <<l <<", " <<r <<endl;
			int len = r - l + 1;
			if(now + len <= k)
			{
				for(int i = l; i <= r; i ++)
					cout <<i <<" ";
				now += len;
			}
			else
			{
				int less = k - now;
				for(int i = 0; i < less; i ++)
					cout <<l + i <<" ";
				break;
			}
		}
		cout <<endl;
	}
	return 0;
}