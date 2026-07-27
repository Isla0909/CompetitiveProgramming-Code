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

	int n, k; cin >>n >>k;
	vector<int> p(n + 1); int sum = 0;
	vector w(n + 1, vector<int>(11));
	for(int i = 1; i <= n; i ++)
	{
		cin >>p[i];
		sum += p[i];
		for(int j = 1; j <= p[i]; j ++)
			cin >>w[i][j];
	}

	int m = min(sum, k);

	vector<int> dp0(m + 1, -INF), dp1(m + 1, -INF);
	dp0[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m; j >= 0; j --)
		{
			if(j - p[i] >= 0 && dp0[j - p[i]] != -INF)
				dp0[j] = max(dp0[j], dp0[j - p[i]] + w[i][p[i]]);

			if(j - p[i] >= 0 && dp1[j - p[i]] != -INF)
				dp1[j] = max(dp1[j], dp1[j - p[i]] + w[i][p[i]]);  

			for(int x = 1; x < p[i]; x ++)
				if(j - x >= 0 && dp0[j - x] != -INF) dp1[j] = max(dp1[j], dp0[j - x] + w[i][x]); 
		}
	}
	cout <<max(dp0[m], dp1[m]) <<endl;
	return 0;
}
