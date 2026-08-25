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

int lev(i64 x)
{
	int res = 0;
	while(x)
	{
		res ++;
		x /= 10;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<i64> p(18);
	p[0] = 1;
	for(int i = 1; i < 18; i ++)
		p[i] = p[i - 1] * 10;

	int n, k; cin >>n >>k;
	i64 sum = 0;
	for(int i = 0; i < n; i ++)
	{
		int x; cin >>x;
		sum += x;
	}

	int siz = lev(sum);
	k = min(k, siz);

	string s = to_string(sum);

	i64 ans = sum;
	for(int len = 1; len <= k; len ++)
	{
		for(int l = 0; l + len - 1 < siz; l ++)
		{
			int r = l + len - 1;
			string pre = s.substr(0, l), mid = s.substr(l, len), suf = s.substr(r + 1);
			reverse(mid.begin(), mid.end());
			i64 res = stoll(pre + mid + suf);
			ans = max(ans, res);
		}
	}
	cout <<ans <<endl;
	return 0;
}
