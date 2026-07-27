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
	for(int i = l; i < 10; i ++)
		cout <<v[i] <<" \n"[i == 10 - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> cnt(101);
	int pre = 0;
	for(int i = 1; i <= n; i ++)
	{
		int res = 0;
		int x; cin >>x;
		if(pre > m - x)
		{
			int sum = pre; int idx = 100;
			while(sum > m - x)
			{
				int tot = cnt[idx] * idx;
				if(sum - tot >= m - x) res += cnt[idx], sum -= tot;
				else
				{
					int delta = sum - (m - x);
					res += (delta + idx - 1) / idx; 
					break;
				}
				idx --;
			}
		}
		pre += x;
		cnt[x] ++;
		// tell(1, cnt);
		// cout <<i <<" " <<pre <<endl;
		cout <<res <<" \n"[i == n]; 
	}

	return 0;
}