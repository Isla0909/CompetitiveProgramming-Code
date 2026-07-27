#pragma GCC optimize(2)
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

struct cxy
{
	int c, f, w;
	int type;

	cxy(int c, int f, int w, int type) : c(c), f(f), w(w), type(type) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<cxy> a; int sum = 0;
	for(int i = 0; i < n; i ++)
	{
		int c, f, w; cin >>c >>f >>w;
		a.emplace_back(c, f, w, 0);
		sum += c;
	}

	int m; cin >>m;
	for(int i = 0; i < m; i ++)
	{
		int c, f, w; cin >>c >>f >>w;
		a.emplace_back(c, f, w, 1);
	}

	sort(a.begin(), a.end(), [&](const cxy &a, const cxy &b)
	{
		if(a.f != b.f) return a.f > b.f;
		return a.type < b.type;
	});

	vector<i64> dp(sum + 1, -inf);
	dp[0] = 0;
	for(auto &[c, f, w, type] : a)
	{
		if(type == 0)
		{
			for(int j = sum; j >= c; j --)
			{
				if(dp[j - c] == -inf) continue;
				dp[j] = max(dp[j], dp[j - c] - w);
			}
		}
		else
		{
			for(int j = 0; j + c <= sum; j ++)
			{
				if(dp[j + c] == -inf) continue;
				dp[j] = max(dp[j], dp[j + c] + w);
			}
		}
	}
	cout <<*max_element(dp.begin(), dp.end()) <<endl;
	return 0;
}
