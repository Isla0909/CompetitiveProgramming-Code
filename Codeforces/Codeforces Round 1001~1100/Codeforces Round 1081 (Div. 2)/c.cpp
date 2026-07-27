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
		int n, h, k; cin >>n >>h >>k;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		i64 s = accumulate(a.begin(), a.end(), 0LL);
		int p = h / s, q = h % s;
		//cout <<p <<" " <<q <<endl;
		if(q == 0)
		{
			cout <<1LL * p * n + 1LL * (p - 1) * k <<endl;
			continue;
		}

		vector<int> pre(n + 1), suf(n + 1);
		pre[1] = a[1], suf[n] = a[n];
		for(int i = 2; i <= n; i ++)
			pre[i] = min(pre[i - 1], a[i]);
		for(int i = n - 1; i >= 1; i --)
			suf[i] = max(suf[i + 1], a[i]);

		i64 sum = 0, ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			sum += a[i];
			i64 res = sum;
			if(i != n)
			{
				res = max(res, sum - pre[i] + suf[i + 1]);
			}
			if(res >= q)
			{
				ans = i;
				break;
			}
		}
		//cout <<ans <<endl;
		cout <<1LL * p * (n + k) + ans <<endl;
	}
	return 0;
}
