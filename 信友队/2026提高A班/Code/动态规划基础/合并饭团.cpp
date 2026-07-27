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

	int n; cin >>n;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	vector<vector<int>> f(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i ++)
		f[i][i] = a[i];

	for(int len = 2; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			int i = l, j = r;
			while(i < j)
			{
				int left = pre[i] - pre[l - 1], right = pre[r] - pre[j - 1];
				if(left < right) i ++;
				else if(right < left) j --;
				else
				{
					bool ok = (i + 1 == j) || f[i + 1][j - 1] > 0;

					if(ok && f[l][i] == f[j][r])
					{
						f[l][r] = max(f[l][r], f[l][i] + f[i + 1][j - 1] + f[j][r]);
						break;
					}
					i ++, j --;
				}
			}
		}

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			ans = max(ans, f[i][j]);
	cout <<ans <<endl;
	return 0;
}
