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

constexpr int N = 3e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

i64 p[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i < N; i ++)
		p[i] = p[i - 1] * 2 % mod;

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;
		s = ' ' + s;

		i64 dp0 = 1, dp1 = 0, ans = 0, pre = 0;
		for(int i = 1; i <= n; i ++)
		{
			char c = s[i];

			if(c == '(') ans = (ans + p[i - 1]);
			else ans = (ans + dp0 + dp1) % mod;

			pre += (c == '(') ? 1 : -1;

			if(c == ')') dp0 = (dp0 + dp0 + dp1) % mod;
			else dp1 = (dp1 + dp0 + dp1) % mod;

			if(pre < 2) dp1 = 0;
		}
		cout <<ans <<endl;
	}
	return 0;
}