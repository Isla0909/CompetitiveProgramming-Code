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
		i64 s; int q; cin >>s >>q;
		vector<i64> div{0};
		for(i64 i = 1; i * i <= s; i ++)
		{
			if(s % i) continue;
			div.push_back(i);
			if(i * i != s) div.push_back(s / i);
		}
		sort(div.begin() + 1, div.end());
		
		int m = div.size() - 1;
		vector<i64> pre(m + 1);
		for(int i = 1; i <= m; i ++)
			pre[i] = pre[i - 1] + (div[i] - div[i - 1]) * (s / div[i]);

		while(q --)
		{
			i64 x, y; cin >>x >>y;
			int r = lower_bound(div.begin(), div.end(), x) - div.begin();
			int k = upper_bound(div.begin(), div.end(), s / y) - div.begin() - 1;

			if(k >= r)
			{
				cout <<x * y <<endl;
				continue;
			}
			i64 ans = div[k] * y;
			ans += pre[r - 1] - pre[k];
			ans += (x - div[r - 1]) * (s / div[r]);
			cout <<ans <<endl;
		}
	}
	return 0;
}
