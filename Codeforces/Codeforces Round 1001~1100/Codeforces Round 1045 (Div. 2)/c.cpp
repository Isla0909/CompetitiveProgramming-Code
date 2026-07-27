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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<i64> &v)
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
		vector<i64> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		
		i64 ans = 0;
		for(int i = 2; i <= n; i += 2)
		{
			i64 s = a[i - 1];
			if(i + 1 <= n) s += a[i + 1];

			if(s > a[i])
			{
				i64 delta = s - a[i];
				ans += delta;
				if(i + 1 <= n)
				{
					if(a[i + 1] >= delta) a[i + 1] -= delta, delta = 0;
					else delta -= a[i + 1], a[i + 1] = 0;
				}
				if(delta) a[i - 1] -= delta;
			}
		}
		//tell(1, a);
		cout <<ans <<endl;
	}
	return 0;
}