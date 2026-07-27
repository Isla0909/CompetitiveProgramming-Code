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
#define int long long
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, ll b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % mod;

		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> p(n), pos1(n), q(n), pos2(n);
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			p[i] = x;
			pos1[x] = i;
		}
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			q[i] = x;
			pos2[x] = i;
		}
		vector<int> r(n); int j = 0;
		for(int i = n - 1; i >= 0; i --)
		{
			int x = pos1[i], limit = n - 1 - x;
			while(j <= limit)
			{
				r[j + x] = (quick_pow(2, i) + quick_pow(2, q[j])) % mod;
				j ++;
			}
		}
		j = 0;
		for(int i = n - 1; i >= 0; i --)
		{
			int x = pos2[i], limit = x;
			cout <<x <<" " <<j <<endl;
			while(j == 0 || j < limit)
			{
				int c = (quick_pow(2, i) + quick_pow(2, p[j])) % mod;
				r[x + j] = max(r[x + j], c);
				j ++;
			}
		}
		tell(r);
	}
	return 0;
}