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

int f(i64 x)
{
	int res = 0;
	while(x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<i64> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		bool flag = 1; int ans = 0;
		for(int i = n - 1; i >= 1; i --)
		{
			while(a[i] >= 10 && a[i] > a[i + 1])
			{
				a[i] = f(a[i]);
				ans ++;
			}
			if(a[i] < 10 && a[i] > a[i + 1])
			{
				flag = 0;
				break;
			}
		}
		cout <<(flag ? ans : -1) <<endl;
	}
	return 0;
}
