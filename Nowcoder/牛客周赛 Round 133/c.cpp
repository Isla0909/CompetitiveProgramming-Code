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

	i64 x, l, r; cin >>x >>l >>r;
	i64 p = 1;
	for(int i = 2; i * i <= x; i ++)
	{
		if(x % i) continue;

		int c = 0;
		while(x % i == 0)
		{
			x /= i;
			c ++;
		}
		if(c & 1) p *= i;
	}
	if(x > 1) p *= x;
	bool f = 0;
	for(int i = 1; ; i ++)
	{
		i64 c = p * i * i;
		if(c >= l && c <= r)
		{
			cout <<c <<endl;
			f = 1;
			break;
		}
		if(c > r) break;
	}
	if(!f) cout <<-1 <<endl;
	return 0;
}
