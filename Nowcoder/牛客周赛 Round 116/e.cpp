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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	i64 sum = accumulate(a.begin(), a.end(), 0LL);

	vector<pii> ans; bool f = 0;
	for(int i = 1; i <= n && !f; i ++)
	{
		while(a[i])
		{
			int j = i, s = a[i];
			while(j + 1 <= n && a[j + 1])
			{
				j ++;
				s = min(s, a[j]);
			}

			for(int k = 0; k < s; k ++)
				ans.emplace_back(i, j);

			if(ans.size() > m)
			{
				f = 1;
				break;
			}

			for(int k = i; k <= j; k ++)
				a[k] -= s;
		}
	}


	if(m < ans.size() || f) cout <<-1 <<endl;
	else
	{
		if(sum < m) cout <<-1 <<endl;
		else
		{
			int delta = m - ans.size();
			for(int i = 0; i < ans.size(); i ++)
			{
				auto [l, r] = ans[i];
				int len = r - l + 1;
				if(delta)
				{
					if(delta >= len - 1)
					{
						for(int i = l; i <= r; i ++)
							cout <<i <<" " <<i <<endl;
						delta -= (len - 1);
					}
					else
					{
						int c = delta;
						for(int i = 0; i < c; i ++)
							cout <<l + i <<" " <<l + i <<endl;
						delta = 0;
						cout <<l + c <<" " <<r <<endl;
					}
				}
				else cout <<l <<" " <<r <<endl;
			}
		}
	}
	return 0;
}
//0 1 0 1 0