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
	cin.tie(0) -> sync_with_stdio(false);

	int n = 500000;
	int len = sqrt(n);

	vector<int> a(n + 1, 0);
	vector f(len + 1, vector<i64>(len));

	int m; cin >>m;
	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int p, x; cin >>p >>x;
			for(int j = 1; j <= len; j ++)
				f[j][p % j] += x;
			a[p] += x;
		}
		else
		{
			int x, y; cin >>x >>y;
			if(x <= len) cout <<f[x][y] <<endl;
			else
			{
				i64 ans = 0;
				for(int i = y; i <= n; i += x)
					ans += a[i];
				cout <<ans <<endl;
			}
		}
	}

	return 0;
}