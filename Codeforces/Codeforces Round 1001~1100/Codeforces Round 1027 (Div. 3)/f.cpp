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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int get(int x, int k)
{
	vector<int> v;
	for(int i = 1; i <= x / i; i ++)
	{
		if(x % i == 0)
		{
			v.push_back(i);
			if(i * i != x) v.push_back(x / i);
		}
	}
	sort(v.begin(), v.end());

	int d = v.size();
	vector<int> f(d, INF);
	f[0] = 0;
	for(int i = 1; i < d; i ++)
		for(int j = 0; j < i; j ++)
		{
			if(v[i] % v[j] == 0 && v[i] / v[j] <= k)
				f[i] = min(f[i], f[j] + 1);
		}
	return f[d - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int x, y, k; cin >>x >>y >>k;
		int g = __gcd(x, y);

		int ans = get(x / g, k) + get(y / g, k);
		if(ans >= INF) cout <<-1 <<endl;
		else cout <<ans <<endl;
	}
	return 0;
}