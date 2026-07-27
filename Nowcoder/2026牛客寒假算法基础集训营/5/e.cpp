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

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

double random(double l, double r)
{
	return 1.0 * rng() / rng.max() * (r - l) + l;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p; cin >>n >>p;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = (pre[i - 1] + a[i]) % p;
	}

	//tell(1, pre);

	int L = 1, R = n, ans = pre[n] % p;
	set<pii> S;
	for(int i = 1; i <= n; i ++)
	{
		auto [x1, idx1] = *S.begin();
		if(pre[i] > x1)
		{
			if(pre[i] - x1 > ans)
			{
				L = idx1 + 1, R = i;
				ans = pre[i] - x1;
			}
		}
		auto it = S.upper_bound({pre[i], INF});
		if(it != S.end())
		{
			auto [x2, idx2] = *it;
			//cout <<i <<" " <<pre[i] <<" " <<x2 <<" " <<idx2 <<endl;
			if(p + pre[i] - x2 > ans)
			{
				L = idx2 + 1, R = i;
				ans = p + pre[i] - x2;
			}
		}
		S.insert({pre[i], i});
	}
	cout <<L - 1 <<" " <<R - 1 <<" " <<ans <<endl;
	return 0;
}
