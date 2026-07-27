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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >>n >>k;
	vector f(n + 1, vector<int>(21));
	f[1][0] = 1;
	for(int i = 2; i <= n; i ++)
	{
		int fa; cin >>fa;
		f[i][0] = fa;
	}
	for(int j = 1; j <= 20; j ++)
		for(int i = 1; i <= n; i ++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	vector<bool> st(n + 1);
	st[1] = 1;
	int ans = -1; bool h = 0;
	while(k --)
	{
		int u, l, r; cin >>u >>l >>r;
		for(int i = l; i <= r; i ++)
		{
			int down = u;
			for(int j = 20; j >= 0; j --)
			{
				int up = f[down][j];
				if(!st[up]) down = up;
			}
			st[down] = 1;

			if(down == u)
			{
				ans = i;
				h = 1;
				break;
			}
		}
		if(h) break;
	}
	cout <<ans <<endl;
	return 0;
}
