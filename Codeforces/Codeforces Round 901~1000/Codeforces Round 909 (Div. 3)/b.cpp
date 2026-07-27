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
		vector<int> a(n + 1);
		vector<i64> pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
		}

		auto calc = [&](int x) -> i64
		{
			vector<i64> v;
			for(int i = 1; i * x <= n; i ++)
			{
				v.push_back(pre[i * x] - pre[(i - 1) * x]);
				// cout <<i * x <<" " <<(i - 1) * x <<endl;
			}
			return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
		};

		i64 ans = -inf; int ansk = 1;
		for(int i = 1; i * i <= n; i ++)
		{
			if(n % i) continue;
			i64 a = calc(i), b = calc(n / i);
			if(a > ans)
			{
				ansk = i;
				ans = a;
			}
			if(b > ans)
			{
				ansk = n / i;
				ans = b;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
