#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	if(n <= 2) cout <<0 <<endl;
	else
	{
		int a = quick_pow(26, n);
		int b = 3 * quick_pow(25, n) % mod;
		int c = 3 * quick_pow(24, n) % mod;
		int d = quick_pow(23, n);
		cout <<(a + 100 * mod - b + c - d) % mod <<endl;
	}
	
	return 0;
}