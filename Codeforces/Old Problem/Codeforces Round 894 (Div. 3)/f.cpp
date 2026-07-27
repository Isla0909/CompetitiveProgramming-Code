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
		int p, q, n; cin >>p >>q >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		int s = n * *max_element(a.begin() + 1, a.end());
		vector<int> f(s + 1); f[0] = 1;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = s; j >= a[i]; j --)
				f[j] |= f[j - a[i]];
		}

		int ans = INF, sum = accumulate(a.begin() + 1, a.end(), 0);
		for(int i = 0; i <= s; i ++)
			if(f[i]) ans = min(ans, max((i + p - 1) / p, (sum - i + q - 1) / q));
		cout <<ans <<endl;
	}
	return 0;
}
