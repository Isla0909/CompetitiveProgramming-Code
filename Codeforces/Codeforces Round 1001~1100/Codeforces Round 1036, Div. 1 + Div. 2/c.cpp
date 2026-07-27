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
#define int long long
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
		int n; cin >>n;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		int d = a[0];
		for(int i = 1; i < n; i ++)
			d = __gcd(d, a[i]);

		auto check = [&]() -> bool
		{
			for(int i = 1; i < n; i ++)
				if(a[i] % a[i - 1]) return false;
			return true;
		};

		if(check())
		{
			cout <<1 <<endl;
			continue;
		}

		auto solve = [&](int x)
		{
			map<int, int> mp;
			for(int i = 2; i <= x / i; i ++)//一个数不可能有两个大于sqrt(n)的因子
		    {
		        if(x % i == 0)
		        {
		            int s = 0;
		            while(x % i == 0)
		            {
		                x /= i;
		                s ++;
		            }
		            mp[i] = s;
		        }
		    }
		    if(x > 1) mp[x] = 1;
		    return mp;
		};

		int x = 1;

		auto check1 = [&]() -> bool
		{
			for(int i = 1; i < n; i ++)
				if(a[i] % a[i - 1])
				{
					int t = a[i - 1] / x;
					if(a[i] % t) return false;
				}
			return true;
		};

		// while(!check1())
		// {
			for(int i = 1; i < n; i ++)
			{
				if(a[i] % a[i - 1])
				{
					int t = a[i - 1] / x;
					if(a[i] % t == 0) continue;

					int gcd = __gcd(a[i], a[i - 1]);

					t = (a[i - 1] / gcd);
					gcd = __gcd(t, x);
					x *= (t / gcd);
				}
			}
		// }
		cout <<x <<endl;
	}
	return 0;
}