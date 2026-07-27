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
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		auto check = [&](int x) -> bool
		{
			vector<int> stk(n + 1); int top = 0;
			for(int i = 1; i <= n; i ++)
			{
				int c = (a[i] >= x);
				if(top >= 2 && !stk[top] && !stk[top - 1])
				{
					top -= 2;
					stk[++ top] == 0;
				}
				else stk[++ top] = c;
			}
			int c0 = 0, c1 = 0;
			for(int i = 1; i <= top; i ++)
			{
				if(stk[i] == 1) c1 ++;
				else c0 ++;
			}
			return c1 - c0 >= 1;
		};

		int l = 0, r = 1e9 + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout <<l <<endl;
	}
	return 0;
}
