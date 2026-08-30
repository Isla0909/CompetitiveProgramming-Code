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
		i64 n, k; cin >>n >>k;
		i64 tot = 0;
		while(n > 1)
		{
			i64 d = (n + k - 1) / k;
			i64 L = (d - 1) * k + 1;
			i64 t = (n - L) / d + 1;
			t = min(t, (n - 1) / d);
			tot += t;
			n -= d * t;
		}
		
		i64 x = 1;
		while(tot > 0)
		{
			i64 d = (x + k - 1 - 1) / (k - 1);
			i64 R = d * (k - 1);
			i64 t = (R - x) / d + 1;
			t = min(t, tot);
			x += t * d;
			tot -= t; 
		}
		cout <<x <<endl;
	}
	return 0;
}
