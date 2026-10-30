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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998857459;

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

	// int x = 998857459;
	// vector<int> div;
	// for(int i = 2; i * i <= x; i ++)
	// {
	// 	if(x % i) continue;
	// 	else 
	// 	{
	// 		x /= i;
	// 		div.push_back(i);
	// 	}
	// }
	// div.push_back(x);
 	// tell(0, div);

	int n, q; cin >>n >>q;
	vector<i64> fac(n + 1);
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;

	vector<i64> pos{0}, val{0};
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		if(fac[x])
		{
			pos.push_back(i);
			val.push_back(fac[x]);
		}
	}

	int m = pos.size() - 1;
	vector<i64> f(n + 1);
	for(int i = 1; i <= m; i ++)
	{
		i64 sum = 0;
		for(int j = i; j <= m; j ++)
		{
			sum = (sum + val[j]) % mod;

			int len = pos[j] - pos[i] + 1;
			f[len] = max(f[len], sum);
		}
	}

	for(int i = 1; i <= n; i ++)
		f[i] = max(f[i], f[i - 1]);

	while(q --)
	{
		int x; cin >>x;
		auto it = lower_bound(f.begin() + 1, f.end(), x);
		if(it == f.end()) cout <<-1 <<endl;
		else cout <<it - f.begin() <<endl;
	}
	return 0;
}
