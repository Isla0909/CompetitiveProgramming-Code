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

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    i128 d = exgcd(b, a % b, x, y);
    i128 x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}

i128 aabs(i128 x)
{
	if(x >= 0) return x;
	return -x; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		i64 s, a, b; cin >>s >>a >>b;
		i64 d = __gcd(a, b);
		if(s % d)
		{
			cout <<"No" <<endl;
			continue;
		}

		i64 k = s / d;

		i128 x, y;
		exgcd(a, b, x, y);
		//cout <<"x and y " <<x <<" " <<y <<endl;
		
		i128 lcm = (i128)a * b / d;
		i128 da = lcm / a, db = lcm / b;

		x *= k, y *= k;
		//cout <<"x and y " <<x <<" " <<y <<endl;
		bool f = 1;
		if(x < 0)
		{
			i128 c = (aabs(x) + da - 1) / da;
			if(y - c * db < 0) f = 0;
			if(f) x += c * da, y -= c * db;
		}
		if(y < 0)
		{
			i128 c = (aabs(y) + db - 1) / db;
			//cout <<c <<endl;
			if(x - c * da < 0) f = 0;
			if(f) x -= c * da, y += c * db;
		}

		if(!f)
		{
			cout <<"No" <<endl;
			continue;
		}
		cout <<"Yes" <<endl;

		if(a == b)
		{
			i64 sum = s / a;
			cout <<sum / 2 <<" " <<sum - sum / 2 <<endl;
			continue;
		}

		//cout <<x <<" " <<y <<endl;
		vector<pair<i128, i128>> ans;
		if(x == y)
		{
			assert(x * a + y * b == s);
			assert(x >= 0 && y >= 0);
			cout <<(i64)x <<" " <<(i64)y <<endl;
		}
		else if(x < y)
		{
			auto check = [&](i64 c) -> bool
			{
				i128 nx = x + (i128)c * da;
				i128 ny = y - (i128)c * db;
				return nx < ny;
			};

			i64 l = -1, r = y / db + 1;
			while(l + 1 != r)
			{
				i64 mid = l + r >> 1;
				if(check(mid)) l = mid;
				else r = mid;
			}
			if(l == -1) l = 0;
			ans.emplace_back(x + l * da, y - l * db);
			if(y - (l + 1) * db >= 0) ans.emplace_back(x + (l + 1) * da, y - (l + 1) * db);

			sort(ans.begin(), ans.end(), [&](auto a, auto b)
			{
				return max(a.ff, a.se) < max(b.ff, b.se);
			});
			assert(ans[0].ff * a + ans[0].se * b == s);
			//assert(ans[0].ff >= 0 && ans[0].se >= 0);
			cout <<(i64)ans[0].ff <<" " <<(i64)ans[0].se <<endl;	
		}
		else//x > y
		{
			auto check = [&](i64 c) -> bool
			{
				i128 nx = x - (i128)c * da;
				i128 ny = y + (i128)c * db;
				return nx > ny;
			};

			i64 l = -1, r = x / da + 1;
			while(l + 1 != r)
			{
				i64 mid = l + r >> 1;
				if(check(mid)) l = mid;
				else r = mid;
			}
			if(l == -1) l = 0;
			ans.emplace_back(x - l * da, y + l * db);
			if(x - (l + 1) * da >= 0) ans.emplace_back(x - (l + 1) * da, y + (l + 1) * db);

			sort(ans.begin(), ans.end(), [&](auto a, auto b)
			{
				return max(a.ff, a.se) < max(b.ff, b.se);
			});
			assert(ans[0].ff * a + ans[0].se * b == s);
			//assert(ans[0].ff >= 0 && ans[0].se >= 0);
			cout <<(i64)ans[0].ff <<" " <<(i64)ans[0].se <<endl;	
		}
	}
	return 0;
}
