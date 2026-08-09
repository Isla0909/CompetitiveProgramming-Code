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
		int a; i64 b; cin >>a >>b;
		int ans = 26;
		auto dfs = [&](this auto &&self, i64 a, i64 b, int s) -> void
		{
			if(s > ans) return ;
			if(a == 0 && b == 0)
			{
				ans = s;
				return ;
			}

			i64 gcd = __gcd(a, b);
			if(a >= gcd) self(a - gcd, b, s + 1);
			if(b >= gcd) self(a, b - gcd, s + 1);
		};
		dfs(a, b, 0);
		cout <<ans <<endl; 
	}
	return 0;
}