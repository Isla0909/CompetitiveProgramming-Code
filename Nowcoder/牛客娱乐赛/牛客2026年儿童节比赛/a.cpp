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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 20260601;

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

	string n; cin >>n;

	vector<int> a = {2, 4, 6, 7, 8};

	int len = n.size();

	vector<int> pw(len + 1);
	pw[0] = 1;
	for(int i = 1; i <= len; i ++)
	{
		pw[i] = 1LL * pw[i - 1] * 5 % mod;
	}

	int ans = 0;

	// 先统计位数小于 len 的数
	for(int i = 1; i < len; i ++)
	{
		ans += pw[i];
		ans %= mod;
	}

	// 再统计位数等于 len，且 <= n 的数
	for(int i = 0; i < len; i ++)
	{
		int d = n[i] - '0';
		int rem = len - i - 1;

		int cnt = 0;
		bool ok = false;

		for(auto x : a)
		{
			if(x < d) cnt ++;
			if(x == d) ok = true;
		}

		ans = (ans + 1LL * cnt * pw[rem]) % mod;

		// 这一位没法和 n 继续保持相等，后面不用看了
		if(!ok)
		{
			cout <<ans <<endl;
			return 0;
		}
	}

	// n 本身每一位也都是 2/4/6/7/8
	ans ++;
	ans %= mod;

	cout <<ans <<endl;

	return 0;
}