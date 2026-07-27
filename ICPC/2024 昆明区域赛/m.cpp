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
		int n, m; cin >>n >>m;
		cout <<"YES" <<endl;
		if(m & 1)
		{
			vector g(n, vector<int>(m)); int idx = 1;
			for(int i = 0; i < n; i ++)
				for(int j = 0; j < m; j ++)
					g[i][(j - i + m * 1000) % m] = idx ++;
			for(int i = 0; i < n; i ++)
				for(int j = 0; j < m; j ++)
					cout <<g[i][j] <<" \n"[j == m - 1];
		}
		else
		{
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
					cout <<(i - 1) * m + j <<" \n"[j == m];
		}
	}
	return 0;
}