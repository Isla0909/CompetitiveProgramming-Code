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

vector<i64> p(16);

i64 get(i64 x)
{
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return stoll(s);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i <= 15; i ++)
		p[i] = p[i - 1] * 10;

	int T; cin >>T;
	while(T --)
	{
		i64 l, r; cin >>l >>r;
		if(r - l + 1 <= 10000)
		{
			i64 ans = 0;
			for(i64 i = l; i <= r; i ++)
				ans = max(ans, get(i));
			cout <<ans <<endl;
		}
		else
		{
			i64 ans = 0;

			int cnt = 100;
			for(int i = 0; i < cnt && l + i <= r; i ++)
				ans = max(ans, get(l + i));

			for(int i = 0; i < cnt && r - i >= l; i ++)
				ans = max(ans, get(r - i));

			auto calc = [&](i64 r, int c) -> i64
			{
				i64 res = p[c] - 1;
				if(r < res) return 0;
				return (r - res) / p[c] * p[c] + res;
				// cout <<(r - res) / p[c] * p[c] + res <<endl;
			};

			for(int c = 0; c <= 15; c ++)
			{
				//calc(r, c);
				i64 x = calc(r, c);
				//cout <<x <<endl;
				if(x >= l) ans = max(ans, get(x));
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}
